# SVG2Keynote-lib: Bridging SVG and Apple Keynote

**Authors:** [Jonathan Lamperth](https://www.linkedin.com/in/jonathan-lamperth-7059b418a) and [Christian Holz](https://www.christianholz.net)
**Affiliation:** [Sensing, Interaction & Perception Lab](https://siplab.org), Department of Computer Science, ETH Zürich

**Project Page:** [SVG2Keynote project page](https://siplab.org/releases/SVG2Keynote)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Overview

`SVG2Keynote-lib` is a powerful C++ library designed to facilitate the conversion of Scalable Vector Graphics (SVG) into native Apple Keynote objects. It also provides experimental support for the reverse process: converting Keynote documents back into SVG format.

The primary purpose of this library is to enable developers to programmatically create, modify, or import vector graphics into Keynote presentations, preserving their editability as native Keynote shapes. This is particularly useful for applications that generate graphics dynamically or require batch processing of SVGs for use in Keynote.

This library is the core engine behind the [SVG2Keynote GUI application](https://github.com/eth-siplab/SVG2Keynote-gui).

### Who is this for?

*   **Developers:** Anyone building tools that need to interoperate with Apple Keynote, especially for importing or exporting vector graphics.
*   **Designers & Researchers:** Individuals who work extensively with both SVGs and Keynote and need to automate their workflow or handle complex graphics.
*   **Users of SVG2Keynote GUI:** While the GUI provides a user-friendly interface, the library itself can be integrated into more complex custom workflows.

### Why is it useful?

*   **Automation:** Automates the transfer of vector graphics to Keynote, saving significant time compared to manual import/export.
*   **Editability:** Converts SVGs into native Keynote shapes, allowing them to be fully edited (resized, reshaped, restyled) within Keynote.
*   **Advanced Workflows:** Enables programmatic generation and manipulation of Keynote content that would be difficult or impossible through the standard Keynote interface.
*   **Cross-Platform (Core Logic):** The core C++ library logic is platform-agnostic. The `svg2key` CLI tool, which handles macOS clipboard interaction, is Objective-C++ based and specific to macOS.

## Installation

### Prerequisites

Before compiling, ensure you have the following dependencies installed:

*   **CMake (version 3.15+):** For building the project.
*   **Boost (version 1.70+):** Specifically the `filesystem` component. Required for the CLI tools.
*   **Protobuf:** For handling Keynote's internal data format.

On macOS, you can install these using Homebrew:

```bash
brew install cmake boost protobuf
```

### Building the Library and CLI Tools

1.  **Clone the repository (with submodules):**
    ```bash
    git clone --recurse-submodules https://github.com/eth-siplab/SVG2Keynote-lib
    cd SVG2Keynote-lib
    ```

2.  **Configure with CMake and build:**
    This will build the `keynote_lib` static library, the `svg2key` CLI tool (for SVG to Keynote clipboard), and the `keynote` CLI tool (experimental, for Keynote to SVG).
    ```bash
    cmake -H. -Bbuild
    make -C build
    ```
    The compiled library (`libkeynote_lib.a`) will be in `build/keynote_lib/`. The executables (`svg2key`, `keynote`) will be located in the `build/` directory.

3.  **Building only the library (optional):**
    If you only need the static library and not the CLI tools:
    ```bash
    cd SVG2Keynote-lib/keynote_lib
    cmake -H. -Bbuild
    make -C build
    ```
    The static library `libkeynote_lib.a` will be in `SVG2Keynote-lib/keynote_lib/build/`.

### Integrating into your C++ Project

1.  **Link the static libraries:**
    *   `libkeynote_lib.a` (from the appropriate build directory, e.g., `build/keynote_lib/libkeynote_lib.a`)
    *   `libsnappy.a` (located in `keynote_lib/lib/libsnappy.a`)
    *   `libstaticZipper.a` (from `build/zipper/libstaticZipper.a` if using Keynote to SVG functionality via the `keynote` executable or its underlying functions).
2.  **Include the header directory:**
    Ensure your compiler's include path points to the `keynote_lib/headers/` directory to access `keynote.h`.
3.  **Link necessary system libraries and dependencies:**
    *   For applications using the SVG to Keynote clipboard functionality on macOS (similar to how `svg2key` works), you'll need to link against the Cocoa framework (Objective-C/C++). The core library functions in `keynote.h` are pure C++.
    *   Ensure you link against Boost::filesystem if your project directly uses parts of the library or CLI tools that depend on it.
    *   Link against the Protobuf shared library.

## Usage

### 1. Command-Line Interface (CLI) - `svg2key` (SVG to Keynote)

The `svg2key` tool (compiled from `svg2key.mm`) converts SVG data into Keynote objects and places them onto the macOS system pasteboard. You can then paste these objects directly into a Keynote slide.

**Function:** Reads SVG data from standard input.
**Output:** Populates the macOS pasteboard with Keynote-compatible objects.

**Example:**
```bash
cat my_graphic.svg | ./build/svg2key
```
After running this command, open Keynote and paste (Cmd+V).

### 2. Programmatic Usage (C++ Library - `keynote_lib`)

You can use `keynote_lib` directly in your C++ applications. The public API is defined in `keynote_lib/headers/keynote.h`.

#### SVG to Keynote Clipboard Data

To convert an SVG string into data suitable for the Keynote clipboard, you need to generate two pieces of data:

*   **`std::string generateTSPNativeDataClipboardFromSVG(std::string svgData)`:**
    Takes a string containing SVG data and returns a string (byte blob) representing the Keynote objects. This data is intended for the `com.apple.iWork.TSPNativeData` pasteboard type on macOS.

*   **`std::string generateTSPNativeMetadataClipboard()`:**
    Generates necessary metadata for the clipboard. This data is intended for the `com.apple.iWork.TSPNativeMetadata` pasteboard type.

**Important:** For successful pasting into Keynote, the macOS pasteboard must contain:
1.  Data from `generateTSPNativeDataClipboardFromSVG` for type `com.apple.iWork.TSPNativeData`.
2.  Data from `generateTSPNativeMetadataClipboard` for type `com.apple.iWork.TSPNativeMetadata`.
3.  Empty data for type `com.apple.iWork.pasteboardState.hasNativeDrawables`.

**Conceptual C++ Example (macOS specific pasteboard handling not shown by library):**
The `svg2key.mm` tool provides a practical example of how to use these functions with the macOS pasteboard. The library itself provides the C++ functions to generate the data blobs.
```cpp
#include "keynote.h" // Assuming keynote_lib/headers is in include path
#include <string>
#include <fstream>
#include <sstream>
#include <iostream> // For std::cout, std::cerr

// Helper function to read SVG file content
std::string readSVGFile(const std::string& filePath) {
    std::ifstream fileStream(filePath);
    std::stringstream buffer;
    if (fileStream) {
        buffer << fileStream.rdbuf();
        fileStream.close();
        return buffer.str();
    }
    // Handle error appropriately in a real application
    std::cerr << "Error: Could not open SVG file: " << filePath << std::endl;
    return "";
}

int main() {
    std::string svgContent = readSVGFile("path/to/your/image.svg");

    if (!svgContent.empty()) {
        std::string tspNativeData = generateTSPNativeDataClipboardFromSVG(svgContent);
        std::string tspNativeMetadata = generateTSPNativeMetadataClipboard();

        // On macOS, you would now use NSPasteboard APIs (typically in Objective-C or Swift)
        // to set these data strings for their respective types.
        // The svg2key.mm tool in this repository demonstrates this.
        //
        // Pseudo-code for macOS pasteboard interaction:
        // NSPasteboard* pasteboard = [NSPasteboard generalPasteboard];
        // [pasteboard clearContents];
        // NSData* nativeData = [NSData dataWithBytes:tspNativeData.c_str() length:tspNativeData.length()];
        // NSData* metadata = [NSData dataWithBytes:tspNativeMetadata.c_str() length:tspNativeMetadata.length()];
        // [pasteboard setData:nativeData forType:@"com.apple.iWork.TSPNativeData"];
        // [pasteboard setData:metadata forType:@"com.apple.iWork.TSPNativeMetadata"];
        // [pasteboard setData:[NSData data] forType:@"com.apple.iWork.pasteboardState.hasNativeDrawables"];

        std::cout << "SVG converted. Data ready for pasteboard integration." << std::endl;
        // For demonstration, print sizes:
        // std::cout << "TSPNativeData size: " << tspNativeData.length() << " bytes" << std::endl;
        // std::cout << "TSPNativeMetadata size: " << tspNativeMetadata.length() << " bytes" << std::endl;
    } else {
        std::cerr << "Error: SVG content is empty." << std::endl;
        return 1;
    }
    return 0;
}
```

### 3. Experimental Keynote to SVG Conversion

The library also provides experimental functionality to convert Keynote files back into SVG.

#### CLI Tool (`keynote`)

The `keynote` executable (found in the `build/` directory after compilation using the main `CMakeLists.txt`) can be used for basic Keynote to SVG conversion.

**Usage:**
```bash
./build/keynote "Path/To/Your/Presentation.key"
```
This will generate an `output.svg` file in the current working directory.

**Note:** This functionality is experimental and primarily designed for single-slide Keynote files. Complex presentations or features may not convert perfectly.

#### Programmatic Usage (C++ Library)

*   **`std::string generateSVGFromKeynoteIWAFiles(const std::vector<keynoteIWAFile>& entries)`:**
    This function takes a vector of `keynoteIWAFile` structs. Each struct contains the name and content (as a byte vector) of an `.iwa` file extracted from a Keynote presentation.

    The `keynoteIWAFile` struct is defined in `keynote_lib/headers/keynote.h`:
    ```cpp
    struct keynoteIWAFile {
        std::string name;
        std::vector<unsigned char> contents;
    };
    ```
    You would need to unzip the `.key` file (which is a ZIP archive, possibly containing an `Index.zip` for older versions) and read the `.iwa` files from its `Index/` directory into these structs. The `zipper` library (included as a submodule) can be used for this purpose. The `main.cpp` file (used to build the `keynote` CLI tool in the original README, now part of the `keynote` executable's source) demonstrates how to use the `zipper` library to extract these files.

## Technical Deep Dive

This section provides a more detailed look into the internal workings of `SVG2Keynote-lib` and guidelines for contributors.

### How SVG2Keynote-lib Works

#### SVG to Keynote Conversion

The conversion from SVG to Keynote objects involves several steps:

1.  **SVG Parsing:** The input SVG data (provided as a string) is parsed to identify its constituent elements like paths, shapes (rectangles, circles, etc.), and their attributes (fills, strokes, transformations). This library utilizes `nanosvg` (a header-only SVG parser included in `keynote_lib/lib/nanosvg/`) for this initial breakdown.
2.  **Element Translation:** The parsed SVG elements are then translated into corresponding Apple Keynote object structures. Keynote represents its objects and their properties using Protocol Buffers (Protobuf).
3.  **Protobuf Object Construction:** The core of the conversion lies in constructing a hierarchy of Protobuf messages that mirror Keynote's internal representation of shapes, styles, and document structure. Key Protobuf messages involved in generating the clipboard data include:
    *   `TSP::PasteboardObject`: The root object for clipboard data, referencing stylesheets and drawable objects.
    *   `KN::PasteboardNativeStorageArchive`: Contains the actual drawable objects (shapes) and information about the source presentation (like dimensions).
    *   `TSWP::ShapeInfoArchive`: Represents individual shapes. This inherits from `TSD::ShapeArchive` and `TSD::DrawableArchive`.
    *   `TSD::GeometryArchive`: Defines the position (x, y) and size (width, height) of a shape.
    *   `TSD::PathSourceArchive`: Crucial for defining the actual geometry of a shape. For SVGs, this often translates to `TSD::BezierPathSourceArchive`, which stores the control points for Bézier curves.
    *   **Styling Archives:**
        *   `TSS::StylesheetArchive`: Manages styles for the document/clipboard.
        *   `TSWP::ShapeStyleArchive` (via `TSD::ShapeStyleArchive` and `TSS::StyleArchive`): Defines the appearance of shapes.
        *   `TSD::ShapeStylePropertiesArchive`: Holds properties like fill, stroke, and opacity.
        *   `TSD::StrokeArchive`: Details for line styles (color, width, cap, join, pattern).
        *   `TSD::FillArchive`: Details for area fills (solid color, gradient, image).
        *   `TSP::Color`: Represents colors in various models (RGB, CMYK, Grayscale) and color spaces (sRGB, P3).
4.  **Serialization to Pasteboard Format:**
    *   The constructed tree of Protobuf objects representing the SVG content is serialized into a binary byte stream. This stream forms the data for the `com.apple.iWork.TSPNativeData` type on the macOS pasteboard.
    *   Separately, a `TSP::PasteboardMetadata` message is created. This message contains information about the Keynote version used to generate the data (e.g., "com.apple.Keynote 11.1", version numbers). This is serialized for the `com.apple.iWork.TSPNativeMetadata` pasteboard type.
    *   As per Keynote's requirements, an empty data object for the type `com.apple.iWork.pasteboardState.hasNativeDrawables` must also be present on the pasteboard.

The library meticulously constructs these Protobuf messages based on the input SVG, mapping SVG features (paths, fills, strokes) to their Keynote equivalents. For an exhaustive description of the Keynote clipboard format and the Protobuf messages involved, please refer to the [Format Documentation](format_documentation/format_documentation.md).

#### Keynote to SVG Conversion (Experimental)

Converting Keynote files back to SVG is a more complex, experimental feature:

1.  **Keynote File Structure:** A modern Keynote file (`.key`) is essentially a ZIP archive. Older versions might appear as macOS packages (folders) but contain an `Index.zip` file.
2.  **`.iwa` Files:** Inside the archive (typically in an `Index/` directory, or within `Index.zip`), Keynote stores its data in multiple `.iwa` (iWork Archive) files. Each `.iwa` file corresponds to a specific part of the document, such as `Slide.iwa`, `DocumentStylesheet.iwa`, etc.
3.  **Snappy Compression & Protobuf:** Each `.iwa` file is a stream of Protobuf messages compressed using Google's Snappy compression algorithm.
4.  **Decompression and Parsing:** The library first uses the `zipper` submodule to access and decompress these `.iwa` files. Then, the Snappy-compressed data is decompressed (using the included `libsnappy.a`). The resulting byte stream is parsed as a sequence of Keynote's Protobuf messages.
5.  **SVG Reconstruction:** The library then attempts to interpret these Protobuf messages (e.g., shape data, path data, styles from `Slide.iwa` and `DocumentStylesheet.iwa`) and reconstruct corresponding SVG elements. This process is inherently challenging due to the richness and complexity of the Keynote format, which may not always have a direct, simple mapping to SVG features.

### Keynote's Protocol Buffer Definitions

Apple Keynote uses Protocol Buffers extensively for its file format and clipboard data structures. However, Apple does not publicly release these `.proto` definition files.

To work with these formats, `SVG2Keynote-lib` relies on a set of scripts located in the `keynote-protos/` directory to extract and prepare these definitions:

*   **`get-protos.sh`:** This script inspects the Keynote application bundle (e.g., `/Applications/Keynote.app`) to find embedded `.proto` definition files. It then uses the `protoc` (Protobuf compiler) tool to generate the corresponding C++ header (`.pb.h`) and implementation (`.pb.cc`) files. These generated files are placed into `keynote-protos/gen/`.
*   **`dump-mappings.sh`:** Keynote uses numerical type IDs to identify different Protobuf messages. This script programmatically starts Keynote, Pages, and Numbers, attaches a debugger (lldb), and extracts the mapping between these internal type IDs and the actual Protobuf message names. This mapping is crucial for correctly deserializing `.iwa` files. The output is typically processed into a C++ source file (e.g., `keynote-protos/mapping/ProtoMapping.cpp`).

**Running these scripts:**

This process is typically only necessary if Apple significantly changes Keynote's internal Protobuf models in a new version, causing `SVG2Keynote-lib` to fail. To run them:

1.  **Prerequisites:**
    *   **Protobuf Compiler (`protoc`):** Must be installed and in your PATH. (`brew install protobuf`).
    *   **System Integrity Protection (SIP) Disabled (for `dump-mappings.sh` only):** Extracting type mappings requires attaching a debugger to running Apple applications, which is blocked by SIP. You must **temporarily disable SIP** to run `dump-mappings.sh`. Please follow Apple's official guide for [disabling and enabling System Integrity Protection](https://developer.apple.com/documentation/security/disabling_and_enabling_system_integrity_protection). **Remember to re-enable SIP immediately afterward.** Disabling SIP can expose your system to security risks.

2.  **Execution:**
    Navigate to the `keynote-protos/` directory and run the scripts:
    ```bash
    cd keynote-protos
    ./get-protos.sh
    ./dump-mappings.sh # Requires SIP to be disabled
    ```
    The scripts are designed to place the generated files in their correct locations within the project. After running them, you may need to recompile the library.

### Coding Conventions and Contributions

We welcome contributions to `SVG2Keynote-lib`! Please adhere to the following guidelines:

*   **Code Style:**
    *   Follow the existing code style found in the C++ (`.cpp`, `.h`) and Objective-C++ (`.mm`) files.
    *   Aim for clarity and maintainability.
    *   Consider using `clang-format` with a style based on the existing code if making significant changes.
*   **Commit Messages:**
    *   Use conventional commit messages. A good format is a short imperative subject line (e.g., "Fix: Correctly parse elliptical arcs") followed by a more detailed body if necessary.
*   **Testing:**
    *   Currently, the project lacks a formal automated test suite. Contributions of tests (e.g., using Google Test or a similar framework for C++ parts) would be highly valuable.
    *   When adding new features or fixing bugs, manually test your changes thoroughly, especially the SVG to Keynote clipboard functionality and, if relevant, the Keynote to SVG conversion.
*   **Pull Requests (PRs):**
    *   Submit PRs against the `main` branch (or as specified by maintainers).
    *   Ensure your PR is focused on a single feature or bug fix.
    *   Clearly describe the changes made and the reasoning behind them.
    *   If your PR addresses an issue, link to it.
*   **Dependencies:**
    *   Avoid introducing new external dependencies unless absolutely necessary and well-justified. The current dependencies (Boost, Protobuf, Snappy, zipper, nanosvg) are carefully chosen.
*   **Working with Protobufs:**
    *   If you modify or add new Protobuf message definitions (which would typically involve re-running the extraction scripts), ensure all generated files (`.pb.h`, `.pb.cc`, and mapping files) are updated and included in your commit.
*   **Documentation:**
    *   Update this `README.md` or other documentation files (like in `format_documentation/`) if your changes affect usage, installation, or internal workings.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

Copyright 2021 Jonathan Lampérth

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## Used Projects and Licenses
This project utilizes several open-source components. We are grateful to their authors and maintainers.

*   **Snappy:** ([LICENSE_SNAPPY](keynote_lib/lib/LICENSE_SNAPPY)) - Included as a static library.
    <details>
    <summary>Show Snappy License Text</summary>

    ```
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
    ```
    </details>

*   **Protocol Buffers (Protobuf):** ([LICENSE_PROTOBUF](keynote_lib/lib/LICENSE_PROTOBUF)) - Required as a dependency (typically linked as a shared library).
    <details>
    <summary>Show Protobuf License Text</summary>

    ```
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
    ```
    </details>

*   **zipper:** ([zipper/LICENSE.md](zipper/LICENSE.md)) - Included as a static library (submodule).
    <details>
    <summary>Show zipper License Text</summary>

    ```md
    The MIT License (MIT)

    Copyright (c) 2015 seb

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
    ```
    </details>

*   **nanosvg:** ([nanosvg/LICENSE.txt](keynote_lib/lib/nanosvg/LICENSE.txt)) - Included as a header-only library.
    <details>
    <summary>Show nanosvg License Text</summary>

    ```
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
    ```
    </details>

## Credits
The development of this library was made possible by building upon the foundational work and insights from several projects and individuals in the iWork file format community:
*   Initial understanding and [documentation](https://github.com/obriensp/iWorkFileFormat/blob/master/Docs/index.md) of the Keynote File Format by [Sean Patrick O'Brien](http://www.obriensp.com) was a crucial starting point.
*   [keynote-parser](https://github.com/psobot/keynote-parser) by [Peter Sobot](https://petersobot.com) provided valuable insights into the format.
*   The scripts for extracting Protobuf definitions and mappings were heavily inspired by the work of [Jon Connel](https://github.com/masaccio)'s project [numbers-parser](https://github.com/masaccio/numbers-parser).
*   [Sean Patrick O'Brien](http://www.obriensp.com)'s [proto-dump](https://github.com/obriensp/proto-dump) was also invaluable for the Protobuf extraction process.

We extend our sincere thanks to these pioneers.

---
