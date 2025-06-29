#!/usr/bin/env bash
echo "Running 'sudo DevToolsSecurity -enable', enter your administrator password if asked"
sudo DevToolsSecurity -enable
mkdir -p app
mkdir -p out
mkdir -p tmp

apps=(
  "Keynote"
  "Numbers"
  "Pages"
)

entitlements="<key>com.apple.security.get-task-allow</key><true/><key>com.apple.security.cs.disable-library-validation</key><true/><key>com.apple.security.cs.allow-jit</key><true/><key>com.apple.security.cs.allow-unsigned-executable-memory</key><true/><key>com.apple.security.cs.allow-dyld-environment-variables</key><true/><key>com.apple.security.cs.allow-dyld-shared-cache</key><true/><key>com.apple.security.cs.disable-executable-page-protection</key><true/><key>com.apple.security.cs.debugger</key><true/><key>com.apple.accounts.appleaccount.fullaccess</key><true/>"; sed 's|<dict>|<dict>$entitlements|g' "${app}.old.entitlements" > "${app}.entitlements"
for appname in "${apps[@]}"; do
    app="./app/$appname.app"
    echo "Processing $appname..."
    rm -rf "$app"
    rm "$app.old.entitlements"
    rm "$app.entitlements"
    cp -R "/Applications/$appname.app" app
    codesign --display --xml --entitlements "${app}.old.entitlements" "$app"
    sed "s|<dict>|<dict>$entitlements|g" "${app}.old.entitlements" > "${app}.entitlements"
    plutil -convert xml1 "${app}.entitlements"
    codesign -s - --deep --force --entitlements "${app}.entitlements" "$app"
    spctl --add --label "Approved" "$app"
    open --hide "$app"
    pid=$(/bin/ps auxwww | awk '/$appname$/{print $2}')
    echo "Waiting a while (10s)"
    sleep 10
    echo 'po [TSPRegistry sharedRegistry]' | /usr/bin/lldb -p $pid > tmp/$appname.dump
    kill -HUP $pid
    cat tmp/$appname.dump | grep '[0-9]* -> 0x\S* \S*\.' | awk '{print $1" "$4}' | tail -n +2 | sort -n -t, -k1,1 > out/$appname_raw.txt
done

# Get all maps which exist in all 3 programs
sort out/Keynote_raw.txt out/Numbers_raw.txt out/Pages_raw.txt | uniq -d | tail -n +2 | sort -n -t, -k1,1 > out/common.txt

grep -v -x -f out/common.txt out/Keynote_raw.txt > out/keynote_clean.txt
grep -v -x -f out/common.txt out/Pages_raw.txt > out/pages_clean.txt
grep -v -x -f out/common.txt out/Numbers_raw.txt > out/numbers_clean.txt


echo "#include \"ProtoMapping.h\"

ProtoMapping::ProtoMapping(std::string type) {
    registerCommonMessageTypes();
    if (type == \"keynote\") {
            registerKeynoteMessageTypes();
    }
}   

" > mapping/ProtoMapping.cpp

echo "void ProtoMapping::registerKeynoteMessageTypes() {" >> mapping/ProtoMapping.cpp

sed 's/\./::/g' out/keynote_clean.txt | awk '{print "\t _messageTypeToPrototypeMap["$1"]" "= new "$2"();"}' >> mapping/ProtoMapping.cpp

echo "}
" >> mapping/ProtoMapping.cpp

echo "void ProtoMapping::registerCommonMessageTypes() {" >> mapping/ProtoMapping.cpp

sed 's/\./::/g' out/common.txt | awk '{print "\t_messageTypeToPrototypeMap["$1"]" "= new "$2"();"}' >> mapping/ProtoMapping.cpp

echo "}" >> mapping/ProtoMapping.cpp


# Cleanup
#rm -rf out
#rm -rf tmp