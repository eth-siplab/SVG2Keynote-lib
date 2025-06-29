#!/usr/bin/env bash
dir=${0%/*}
if [ "$dir" = "$0" ]; then dir="."; fi
cd "$dir"
git submodule update --init --recursive
echo "Running: brew install snappy protobuf boost"
brew uninstall --ignore-dependencies snappy protobuf boost
brew install snappy protobuf boost && brew link --overwrite protobuf
echo "Extracting protos from /Applications/Keynote.app..."
cd keynote-protos
./get-protos.sh
## THIS FAILS ## ./dump-mappings.sh
cd ..

