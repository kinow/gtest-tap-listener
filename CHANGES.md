## 0.8 (??/??/202?)

- fix(tap.h): Adding ' ...' to correctly end a YAML block #19 thanks @Samxamnom

## 0.7 (26/02/2023)

- Added extensions to project files (e.g. LICENSE.md), preferring Markdown where possible (for GitHub).
- Updated Changelog to include existing releases.
- Added initial CMake configuration (probably needs some more working - pull requests are welcome!).
- Added `CONTRIBUTING.md`.
- Made all GitHub documentation files Markdown.
- Renamed `samples` to `examples`
- Added CI with GitHub Actions (builds main library/interface and also an example executable).
- Added more documentation (including definitions/directives).

## 0.6 (07/05/2016)

- Added `cstdlib`
- Added support to reading a TAP file prefix from env var `GTEST_TAP_FILENAME_PREFIX`

## 0.5 (04/12/2015)

- Add `algorithm` (due to `search` call)

## 0.4 (14/05/2015)

- Added TAP 13 Version TAP header
- Added TAP test numbers
- Prints comments as diagnostics if `GTEST_TAP_13_DIAGNOSTIC` is defined

## 0.3 (08/05/2015)

* Update docs
* Created first tag for project

## 0.2

* Removed CMakefile
* Added Makefile for running samples
* Removed objects for tests for simplicity
* Removed call to comments attribute as this has been removed in Google Test

## 0.1

* Initial implementation of the TAP protocol with a GTest event listener
* OK test status
* NOT_OK test status
* SKIP directive
* Comments
* Test Plan
* One TAP file for each GTest Test Case
* Output TAP file
