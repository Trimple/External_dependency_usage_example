cmake_minimum_required(VERSION 3.10)

project(Submodules_based_external_dep VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11) # C++ standard to use
set(CMAKE_CXX_EXTENSIONS OFF) # Do not allow compiler specific features

add_subdirectory("../../External_dependency_external_source_example" "${CMAKE_CURRENT_LIST_DIR}/external_build/")

add_executable(external_cmake_example app_external_cmake_source.cpp)
target_link_libraries(external_cmake_example PUBLIC external_dep_1)

add_executable(external_no_cmake_example app_external_no_cmake_source.cpp)
target_include_directories(external_no_cmake_example PUBLIC "../../External_dependency_external_source_example/dep_2_no_cmake")