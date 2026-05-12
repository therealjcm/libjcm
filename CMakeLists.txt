cmake_minimum_required(VERSION 3.14)
project(CII_Modern LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Useful warnings
if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Option to build with sanitizers (great for development)
option(ENABLE_SANITIZERS "Enable Address/UB sanitizers" OFF)
if(ENABLE_SANITIZERS)
    add_compile_options(-fsanitize=address,undefined)
    add_link_options(-fsanitize=address,undefined)
endif()

# Library
add_library(cii INTERFACE)  # Or STATIC if you combine multiple modules later

add_library(arith STATIC src/arith.c)
target_include_directories(arith PUBLIC include)

#add_executable(arith_example examples/arith_test.c)
#target_link_libraries(arith_example PRIVATE arith)

# Tests (using CTest)
#enable_testing()
#add_executable(arith_test tests/arith_test.c)
#target_link_libraries(arith_test PRIVATE arith)
#add_test(NAME ArithTests COMMAND arith_test)

# Install rules (optional)
install(TARGETS arith DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
