#!/bin/bash

src_dir="src"
output_dir="output"

compiler="g++"

# Map operating system to output file extension
case "$(uname -s)" in
  Linux*) output_ext="so";;
  Darwin*) output_ext="dylib";;
  CYGWIN*|MINGW*) output_ext="dll";;
  *) echo "Unsupported operating system."; exit 1;;
esac

# Create the output directory if it doesn't exist
mkdir -p "$output_dir"

# Compile the shared library
$compiler -shared -o "$output_dir/mylibrary.$output_ext" "$src_dir"/*.{hpp,h}

# Check if compilation was successful
if [ $? -eq 0 ]; then
  echo "Compilation successful. The shared library is in $output_dir/mylibrary.$output_ext"
else
  echo "Compilation failed."
fi
