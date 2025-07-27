#include "iostream"
#include "submodule_dep_2.hpp"

int main ( )
{
    std::cout << "Running submodules source main\n";

    run_cmake_dep_2();
}