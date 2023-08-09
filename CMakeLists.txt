message("Processing CMakeLists.txt...")

cmake_minimum_required(VERSION 3.27.1) # specify that the currently stable version of CMake is required to build the project
project(elen3009-lab-2)

## ======= Declare Variables =======
set(DOCTEST_PATH "${FETCHCONTENT_BASE_DIR}/doctest-src/doctest/") # path to doctest folder
set(SRC_PATH "${CMAKE_SOURCE_DIR}/src/text-query-system/code/") # path to source code folder
set(MAIN_CPP "main.cpp") # your main cpp file
set(EXE_NAME "TextQuery") # main executable
set(TESTS_EXE_NAME "TextQueryTests") # test executable
set(OUTPUT_DIR "bin") # output directory for all executables

# CONFIGURE_DEPENDS is used to make sure that the globbing is re-run when a new file is added
file(GLOB EXE_SRC CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/text-query-system/code/*.cpp)
file(GLOB TESTS_SRC CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/text-query-system/code/*.cpp ${CMAKE_SOURCE_DIR}/src/text-query-system/tests/*.cpp) # use all cpp files in text-query-system except for MAIN_CPP
list(FILTER TESTS_SRC EXCLUDE REGEX ${MAIN_CPP})
message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message("TESTS_SRC: ${TESTS_SRC}")

# ====================== Setup Targets ======================

# Text Query executable
add_executable(${EXE_NAME} ${EXE_SRC})
target_compile_features(${EXE_NAME} PRIVATE cxx_std_17) # enable C++17 features for the target
set_target_properties(${EXE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}) # produce the executable in the bin directory

# Test executable
add_executable(${TESTS_EXE_NAME} ${TESTS_SRC})
include_directories(${DOCTEST_PATH})
target_include_directories(${TESTS_EXE_NAME} PRIVATE ${SRC_PATH})
target_compile_features(${TESTS_EXE_NAME} PRIVATE cxx_std_17) # enable C++17 features for the target
set_target_properties(${TESTS_EXE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}) # produce the executable in the bin directory'

# ====================== Download Dependencies ======================

include(FetchContent) # include the FetchContent module

# Download doctest
FetchContent_Declare(
    doctest
    # specify the repository URL
    GIT_REPOSITORY https://github.com/doctest/doctest.git
    # corresponds to doctest v2.4.11 - good practice to specify the commit hash as tags can be moved
    GIT_TAG "ae7a13539fb71f270b87eb2e874fbac80bc8dda2" )

# make the dependencies available to the build system
FetchContent_MakeAvailable(doctest)

