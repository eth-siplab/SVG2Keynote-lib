#!/usr/bin/env bash
dir=${0%/*}
if [ "$dir" = "$0" ]; then dir="."; fi
cd "$dir"
arch=$(uname -m)

echo "Generating Makefile for '$arch'..."
mkdir -p build/$arch
cd build/$arch || exit
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_OSX_ARCHITECTURES=$arch ../..
echo "Building for '$arch'..."
make
cd ../..
mkdir -p dist/$arch
cp "build/$arch/svg2key" "dist/$arch/"

