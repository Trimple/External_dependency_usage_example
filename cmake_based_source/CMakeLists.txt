cmake_minimum_required(VERSION 3.10)

project(CMake_based_external_dep VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11) # C++ standard to use
set(CMAKE_CXX_EXTENSIONS OFF) # Do not allow compiler specific features

include(FetchContent)

# Will add google tests to the build
FetchContent_Declare(
    cmake_deps_source
    GIT_REPOSITORY https://github.com/Trimple/External_dependency_cmake_source_example
    GIT_TAG main # pull the last commit from main branch
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(cmake_deps_source)


add_executable(cmake_cmake_example app_cmake_cmake_source.cpp)
target_link_libraries(cmake_cmake_example PUBLIC cmake_dep_1)

# Actually building a C/C++ as a CMake without it being Cmake right away doesn't make any sence, therefore we assume that libraries like these are intended
#   to be .h-file only
# Include directory path will have name from FetchContent_Declare() command, this name can be whatever and isn't used directly in building process as far as I know
add_executable(cmake_no_cmake_example app_cmake_no_cmake_source.cpp)
target_include_directories(cmake_no_cmake_example PUBLIC "./build/_deps/cmake_deps_source-src/dep_2_no_cmake/")
# target_include_directories(cmake_no_cmake_example PUBLIC "${CMAKE_CURRENT_LIST_DIR}/build/_deps/cmake_deps_source-src/dep_2_no_cmake") #same result as line above