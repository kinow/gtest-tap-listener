# GTest TAP Listener

[![CI](https://github.com/kinow/gtest-tap-listener/actions/workflows/ci.yml/badge.svg)](https://github.com/kinow/gtest-tap-listener/actions/workflows/ci.yml)

## Overview

This is a small contribution to Google Test. Oliver and I were working on an 
issue in Jenkins plug-in when he told me about Google Test. As this plug-in 
relies heavily on TAP, we talked about how it looked like a good idea have TAP 
in GoogleTest.

Although GoogleTest has an XML writer, it lacks a TAP one. Using its Event 
Listeners model it was quite easy to implement this first version of this TAP 
listener.

See the [`examples`](https://github.com/kinow/gtest-tap-listener/tree/master/examples)
directory for code to be used as reference.

## Write to `stdout`

By default, the GoogleTest TAP Listener emits TAP to files with names that match the
test names. If you prefer to have the output written to `stdout`, use the definition
`GTEST_TAP_PRINT_TO_STDOUT` when compiling your project.

## Changelog

See [`CHANGES.md`](CHANGES.md).

## Contributions

Feel free to send contributions, pull requests, suggestions or any other feedback to the project.

See [`CONTRIBUTING.md`](CONTRIBUTING.md).

## Authors

A list of contributors to this repository can be found in [`CONTRIBUTORS.txt`](CONTRIBUTORS.txt).

## Links

- <https://github.com/kinow/gtest-tap-listener>
- <https://github.com/google/googletest>
- <https://tupilabs.com/tap4j/>

## License

Licensed under MIT. See [`LICENSE.txt`](LICENSE.txt).
