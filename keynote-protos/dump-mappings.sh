#! /bin/bash
numbers="/Applications/Numbers.app"
keynote="/Applications/Keynote.app"
pages="/Applications/Pages.app"
mkdir -p out
mkdir -p tmp

open --hide -a "$keynote"
open --hide -a "$numbers"
open --hide -a "$pages"
pid_keynote=`/bin/ps auxwww | awk '/Keynote$/{print $2}'`
pid_pages=`/bin/ps auxwww | awk '/Pages$/{print $2}'`
pid_numbers=`/bin/ps auxwww | awk '/Numbers$/{print $2}'`

echo "Waiting a while (10s)"
sleep 10

echo 'po [TSPRegistry sharedRegistry]' | /usr/bin/lldb -p $pid_keynote > tmp/Keynote.dump
echo 'po [TSPRegistry sharedRegistry]' | /usr/bin/lldb -p $pid_numbers > tmp/Numbers.dump
echo 'po [TSPRegistry sharedRegistry]' | /usr/bin/lldb -p $pid_pages > tmp/Pages.dump



kill -HUP $pid_keynote
kill -HUP $pid_pages
kill -HUP $pid_numbers

cat tmp/Keynote.dump | grep '[0-9]* -> 0x\S* \S*\.' | awk '{print $1" "$4}' | tail -n +2 | sort -n -t, -k1,1 > out/keynote_raw.txt
cat tmp/Numbers.dump | grep '[0-9]* -> 0x\S* \S*\.' | awk '{print $1" "$4}'| tail -n +2 | sort -n -t, -k1,1 > out/numbers_raw.txt
cat tmp/Pages.dump | grep '[0-9]* -> 0x\S* \S*\.' | awk '{print $1" "$4}' | tail -n +2 | sort -n -t, -k1,1> out/pages_raw.txt


# Get all maps which exist in all 3 programs
sort out/keynote_raw.txt out/numbers_raw.txt out/pages_raw.txt | uniq -d | tail -n +2 | sort -n -t, -k1,1 > out/common.txt

grep -v -x -f out/common.txt out/keynote_raw.txt > out/keynote_clean.txt
grep -v -x -f out/common.txt out/pages_raw.txt > out/pages_clean.txt
grep -v -x -f out/common.txt out/numbers_raw.txt > out/numbers_clean.txt


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
rm -rf out
rm -rf tmp