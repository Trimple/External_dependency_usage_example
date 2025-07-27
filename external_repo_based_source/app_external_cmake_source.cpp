#include "iostream"
#include "external_dep_1.hpp"

int main ( )
{
    std::cout << "Running external source main\n";

    run_cmake_dep_1();
}