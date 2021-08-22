# Keynote Library Documentation

To see documentation of the keynote file format click [here](format_documentation/format_documentation.md).

## Compilation

### Dependancies
Note in order to compile these tools 2 shared libraries are required: Protobuf and Boost (only required for the command line tool). These can be installed as follows using homebrew:

```
brew install boost
brew install protobuf
```

### Build
This project is built upon CMake. To compile this it is as simple as running the following from the command line:
This first set of commands builds the complete library, as well as a command line application, which can be used to demonstrate basic Keynote to SVG conversion.

```bash
git clone --recurse-submodules https://github.com/eth-siplab/SVG2Keynote-lib
cd SVG2Keynote-lib
cmake -H. -Bbuild
make -C build
```

Afterwards you should be able to find the compiled static library inside of the build folder, and also find an executable `keynote` to test the libraries functionality.

Alternatively if you would only like to compile the library without the demonstration command line tool you can run the following:

```bash
git clone --recurse-submodules https://github.com/eth-siplab/SVG2Keynote-lib
cd SVG2Keynote-lib/keynote_lib
cmake -H. -Bbuild
make -C build
```

### Adding to your own project
Depending on which method was used to build the project there should be a file `libkeynote_lib.a` inside of the build folder. You must then link this file to your project and include `keynote_lib/headers/keynote.h`, to be able to access the public function calls. You should also statically link `keynote_lib/lib/libsnappy.a` to your project. 


## Supported Functionality and Usage

All of the following functions are exposed in `./keynote_lib/header/keynote.h`

### SVG → Keynote

- Function: `generateTSPNativeDataClipboardFromSVG(std::string svgData)`
    - Supports converting a SVG file passed as an std::string to a keynote clipboard. This then must be added to the apple clipboard and can then be pasted. This should be added to Apple's pasteboard for the type: `com.apple.iWork.TSPNativeData`
        - See usage in [KeynoteSVGUI](https://github.com/eth-siplab/SVG2Keynote-gui)
        - See further explanation in [File Format Documentation](ormat_documentation/format_documentation.md)
- Function: `generateTSPNativeMetadataClipboard()` 
    - This function generates the TSPNativeMetadata, which is required for generating a full keynote clipboard.  This function takes no arguments, as it generates generic metadata, which just contains a keynote version. If not added to the clipboard, keynote will not recognise the TSPNativeData. This should be added to apples pasteboard for the type `com.apple.iWork.TSPNativeMetadata`.
        - See usage in [KeynoteSVGUI](https://github.com/eth-siplab/SVG2Keynote-gui)
        - See further explanation in [File Format Documentation](ormat_documentation/format_documentation.md)

### Keynote → SVG (Experimental)

Once you have built the project according to the beginning of the documentation you will find an executable `keynote` inside the build folder. This executable can be used for basic Keynote → SVG conversion as follows:

```bash
./keynote <Path To ".key" file>
```

You will then find a file `output.svg` inside the folder where this is run from. This is designed only to work on a single slide Keynote file and is currently only usable for demonstration purpose and must be enhanced for a viable use case. 

This functionality is exposed in `keynote_lib/keynote.h` by the function: `std::string generateSVGFromKeynoteIWAFiles(const std::vector<keynoteIWAFile>& entries);`

This function requires a std::vector containing the name and contents of the `.iwa` files inside of the `.key` file.

For a better understanding of how to access these `.iwa` files please see:

- [File Format Documentation](format_documentation/format_documentation.md)
- The following implementation for the demonstration command line tool in main.cpp:
<details>
<summary>Code snippet</summary>

```cpp
zipper::Unzipper* currentZip;
    // check if contains index.zip, otherwise extract the .key file as it will be newer format.
    if (file_exists(filePath + "/Index.zip")) {
        currentZip = new zipper::Unzipper(filePath + "/Index.zip");

    } else {
        currentZip = new zipper::Unzipper(filePath);
    }

    std::vector<zipper::ZipEntry> entries = currentZip->entries();

    // erase all entries which are not ".iwa" files.
    entries.erase(
            std::remove_if(entries.begin(),
                            entries.end(),
                            [](const zipper::ZipEntry& entry){
                                return !ends_with(entry.name, ".iwa");
                            }),
            entries.end());

    std::vector<keynoteIWAFile> entriesInMemory(entries.size());
    std::transform(entries.begin(), entries.end(), entriesInMemory.begin(), [&](auto const &x) {
                        keynoteIWAFile entry;
                        entry.name = x.name;
                        currentZip->extractEntryToMemory(x.name, entry.contents);
                        return entry;
                    }
    );
```
</details>



## Extracting Protobuf Definitions and Mapping
In order to be able to use Keynote's Protobuf definitions we need to get these definitions, convert them to a format which c++ understands and then need to find Apple's mapping from type id to the actual type. Currently this step is not necessary, but if Apple decides to make changes to their models and you receive errors, these steps should be followed:

```
cd keynote-protos
./get-protos.sh
./dump-mappings.sh
```

In order for these commands to work you need to meet the following requirements:
1. Protobuf must be installed. This can be done with:  `brew install protobuf`. This makes sure you have the `protoc` command line tool which is necessary to run these scripts.
2. You need to temporarily disable system integrity protection. This can be done according to [Apple's offical guide](https://developer.apple.com/documentation/security/disabling_and_enabling_system_integrity_protection). This step is necessary, so that we can attach the debugger to Keynote and extract the Protobuf mappings.

The first script we run `get-protos.sh` goes through the Keynote executables and searches for `.proto` definition and extracts them. It then uses `protoc` to convert these `.proto` definitions into c++ classes.

The second script we run `dump-mappings.sh` starts Keynote, Pages and Numbers in the background and then attaches a debugger. Then it reads the necessary values, closes the applications and converts them to a format which we can use in this library.

Both these scripts move the files to the correct locaction so all you have to do is run them.

## Credits

Initial understanding and [documentation](https://github.com/obriensp/iWorkFileFormat/blob/master/Docs/index.md) of the Keynote File Format by [Sean Patrick O'Brien](http://www.obriensp.com) was used as a building block for the beginning of this project.

[keynote-parser](https://github.com/psobot/keynote-parser) made by [Peter Sobot](https://petersobot.com) was also used to gain an initial understanding of the format.

The scripts for extracting the Protobuf definitions and Protobuf mappings were heavily inspired by the work of [Jon Connel](https://github.com/masaccio)'s project [numbers-parser](https://github.com/masaccio/numbers-parser) and [Sean Patrick O'Brien](http://www.obriensp.com)'s [proto-dump](https://github.com/obriensp/proto-dump) was also invaluable for this process.

## Used Projects and Licenses
[Snappy](keynote_lib/lib/LICENSE_SNAPPY) - included as a static library
<details>
<summary>Show License Text</summary>

```md
Copyright 2011, Google Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

    * Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
copyright notice, this list of conditions and the following disclaimer
in the documentation and/or other materials provided with the
distribution.
    * Neither the name of Google Inc. nor the names of its
contributors may be used to endorse or promote products derived from
this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

===

Some of the benchmark data in testdata/ is licensed differently:

 - fireworks.jpeg is Copyright 2013 Steinar H. Gunderson, and
   is licensed under the Creative Commons Attribution 3.0 license
   (CC-BY-3.0). See https://creativecommons.org/licenses/by/3.0/
   for more information.

 - kppkn.gtb is taken from the Gaviota chess tablebase set, and
   is licensed under the MIT License. See
   https://sites.google.com/site/gaviotachessengine/Home/endgame-tablebases-1
   for more information.

 - paper-100k.pdf is an excerpt (bytes 92160 to 194560) from the paper
   “Combinatorial Modeling of Chromatin Features Quantitatively Predicts DNA
   Replication Timing in _Drosophila_” by Federico Comoglio and Renato Paro,
   which is licensed under the CC-BY license. See
   http://www.ploscompbiol.org/static/license for more ifnormation.

 - alice29.txt, asyoulik.txt, plrabn12.txt and lcet10.txt are from Project
   Gutenberg. The first three have expired copyrights and are in the public
   domain; the latter does not have expired copyright, but is still in the
   public domain according to the license information
   (http://www.gutenberg.org/ebooks/53).

````
</details>

<br />

[Protobuf](keynote_lib/lib/LICENSE_PROTOBUF) - required as dependancy in the form of a shared library
<details>
<summary>Show License Text</summary>

```md
Copyright 2008 Google Inc.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

    * Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
copyright notice, this list of conditions and the following disclaimer
in the documentation and/or other materials provided with the
distribution.
    * Neither the name of Google Inc. nor the names of its
contributors may be used to endorse or promote products derived from
this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Code generated by the Protocol Buffer compiler is owned by the owner
of the input file used when generating it.  This code is not
standalone and requires a support library to be linked with it.  This
support library is itself covered by the above license.
````
</details>
<br />


[zipper](zipper/LICENSE.md) - included as a static library
<details>
<summary>Show License Text</summary>

```md
The MIT License (MIT)

Copyright (c) 2015 seb

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
````
</details>

<br />

[nanosvg](keynote_lib/lib/nanosvg/LICENSE.txt) - included as header only library

<details>
<summary>Show License Text</summary>

```md
Copyright (c) 2013-14 Mikko Mononen memon@inside.org

This software is provided 'as-is', without any express or implied
warranty.  In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
claim that you wrote the original software. If you use this software
in a product, an acknowledgment in the product documentation would be
appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.


````
</details>