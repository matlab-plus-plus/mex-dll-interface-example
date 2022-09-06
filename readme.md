Example setup for interacting with a generated .dll through Matlab with a Mex function.

This project walks you through the process of creating a mex function that loads a .dll file so that it can be interfaced with Matlab. This uses CMake as the build system generator and requires the following dependencies:
1. CMake version 3.22 or later
2. A C++ compiler capable of C++20 or later (Visual Studio 2019 is what I used)
3. Matlab version 9.8 (R2020a)