# Overview

google/fruit#130

## Requirements

* CMake
* [conan](https://conan.io/) (package manager)

If you do not want to use conan, replace `CMakeLists.txt`.

```diff
 cmake_minimum_required(VERSION 3.13.0)
 project(fruit_issue_130 VERSION 0.1.0)

-################################################################################
-# https://github.com/conan-io/cmake-conan
-
-# Download automatically, you can also just copy the conan.cmake file
-if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
-   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
-   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
-                 "${CMAKE_BINARY_DIR}/conan.cmake"
-                 TLS_VERIFY ON)
-endif()
-
-include(${CMAKE_BINARY_DIR}/conan.cmake)
-
-conan_cmake_run(REQUIRES fruit/3.6.0
-                BASIC_SETUP CMAKE_TARGETS
-                BUILD missing)
-
-# https://github.com/conan-io/cmake-conan
-################################################################################
+find_package(fruit REQUIRED)

 set(FRUIT_ISSUE_130_SOURCE
     src/IClass.cpp
 add_executable(fruit_issue_130
     main.cpp)
 target_link_libraries(fruit_issue_130
     PUBLIC
-        CONAN_PKG::fruit)
+        fruit)
 target_include_directories(fruit_issue_130
     PUBLIC
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
```

## Build and Run

```bash
# Build
$ cd ${PROJECT_DIR}
$ mkdir build
$ cd build
$ cmake -G "${YOUR_GENERATOR}" ..
$ cmake --build . --target all
# Run
$ fruit_issue_130
```
