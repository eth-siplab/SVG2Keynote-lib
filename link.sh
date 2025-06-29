#!/usr/bin/env bash
dir=${0%/*}
if [ "$dir" = "$0" ]; then dir="."; fi
cd "$dir"
lipo -create -output "dist/svg2key" "dist/x86_64/svg2key" "dist/arm64/svg2key"
