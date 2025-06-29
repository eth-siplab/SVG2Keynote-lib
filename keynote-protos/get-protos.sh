#! /bin/bash
dir=${0%/*}; if [ "$dir" = "$0" ]; then dir="."; fi; cd "$dir"; 
# The `proto-dump` tool is from https://github.com/obriensp/proto-dump
echo "Dumping protos..."
PROTO_DUMP=$(pwd)/proto-dump
keynote="/Applications/Keynote.app"

get_data() {
  binfile="$1"
  while read -r data; do
	data=$(echo "$data" | sed 's/:.*Mach-O.*//')
	echo "Copying $data to $binfile"
	cat "$data" >> "$binfile"
  done
}

rm -rf tmp
mkdir tmp
rm -rf protos
mkdir protos

find "$keynote/Contents" -type f -print0 | xargs -0 file | grep 'Mach-O.*binary' | get_data "tmp/keynotebin"

"$PROTO_DUMP" --output=tmp/protos/ tmp/keynotebin || fatal_error "$PROTO_DUMP: error"

rm -rf other/protos
cp -a tmp/protos/keynotebin/. other/protos
rm -rf tmp

rm -rf gen
mkdir gen
protoc -I=other/protos --cpp_out=gen other/protos/*.proto
