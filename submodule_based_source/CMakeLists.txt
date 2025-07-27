cmake_minimum_required(VERSION 3.10)

project(Submodules_based_external_dep VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11) # C++ standard to use
set(CMAKE_CXX_EXTENSIONS OFF) # Do not allow compiler specific features

add_subdirectory(External_dependency_submodule_source_example)

add_executable(submodules_cmake_example app_submodules_cmake_source.cpp)
target_link_libraries(submodules_cmake_example PUBLIC submodule_dep_1)

add_executable(submodules_no_cmake_example app_submodules_no_cmake_source.cpp)
target_include_directories(submodules_no_cmake_example PUBLIC "./External_dependency_submodule_source_example/dep_2_no_cmake")