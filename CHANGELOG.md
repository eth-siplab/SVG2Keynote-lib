# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]
### Added
- Initial project management files: PLAN.md, TODO.md, CHANGELOG.md (2025-06-25)

### Changed
- Improved `svg2key` tool:
    - Renamed misleading parameter in Objective-C wrapper.
    - Added missing `com.apple.iWork.pasteboardState.hasNativeDrawables` pasteboard type.
    - Implemented basic error handling for input and conversion steps.
    - Corrected include path to use canonical `keynote_lib/headers/keynote.h`.

### Removed
- Deleted redundant and problematic `keynote.hpp` from project root.

### Changed
- Refactored `keynote_lib` for improved clarity and robustness:
    - Renamed `filePath` parameter to `svgData` in `generateTSPNativeDataClipboardFromSVG` for accuracy.
    - Fixed memory leak in SVG to Keynote conversion by returning vector of messages by value instead of a raw pointer.
    - Updated internal functions `convertSVGFileToKeynoteClipboard` and `createInitialClipboardMessages` to support this change.
- Cleaned `keynote_lib` public API:
    - Removed unimplemented `decodeAddSquareDecode` function declaration from `keynote_lib/headers/keynote.h`.
