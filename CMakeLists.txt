cmake_minimum_required(VERSION 3.13.0)
project(fruit_issue_130 VERSION 0.1.0)

################################################################################
# https://github.com/conan-io/cmake-conan

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake"
                 TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(REQUIRES fruit/3.6.0
                BASIC_SETUP CMAKE_TARGETS
                BUILD missing)

# https://github.com/conan-io/cmake-conan
################################################################################

set(FRUIT_ISSUE_130_SOURCE
    src/IClass.cpp
    src/IClassImpl.cpp
    src/OuterClass.cpp
    src/FruitComponents.cpp)

add_executable(fruit_issue_130
    ${FRUIT_ISSUE_130_SOURCE}
    main.cpp)
target_link_libraries(fruit_issue_130
    PUBLIC
        CONAN_PKG::fruit)
target_include_directories(fruit_issue_130
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
