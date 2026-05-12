## Build Commands
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_SANITIZERS=ON ..
cmake --build .
ctest

## Acknowledgments
This library is a modern re-implementation based on the interfaces and designs from
David R. Hanson’s book *"C Interfaces and Implementations"* (1997). The original
source code is available at https://github.com/drh/cii and is used under the MIT
license. Many thanks to David Hanson for the excellent foundational work.
