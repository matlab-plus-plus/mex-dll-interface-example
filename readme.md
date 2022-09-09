# Mex <-> DLL Interface Example
Example setup for interacting with a generated .dll through Matlab with a Mex function.
### Background
This project walks you through the process of creating a mex function that loads a .dll file so that it can be interfaced with Matlab. This is especially useful when testing generated C/C++ code since Matlab doesn't have a way to natively load .DLL functions directly.
One benefit of using this method is that you can use Matlab code to test your code-generated Matlab functions. This is a good selling point because the [Matlab Unit Testing Framework](https://www.mathworks.com/help/matlab/matlab-unit-test-framework.html) is very powerful and easy to use effectively. You're also probably more likely to get better quality/quantity of tests if they're written in a language familiar to the writer of the initial code.
Another benefit would be the ability to interface with third-party DLLs through Matlab. Presently, the code example in this repository illustrates how to work in the case where you have access to full source, but a slight modification would make this work for a precompiled DLL file. You just need to write the CMake code to import it as an external library target (if it doesn't already come included with your .dll file).
### Dependencies
This uses CMake as the build system generator and requires the following dependencies:
* [CMake](https://cmake.org/download/) version 3.22 or later
* A Windows C++11 (or later) compiler (I used Visual Studio 2019)
* Matlab version 9.8 (R2020a)
* Windows 7 or later

In principle, you could apply a lot of the same principles to non-Windows systems, but this code won't work out-of-the-box in that case. Linux doesn't use DLLs, but rather what they call 'Shared Objects' (.so files). MacOS has its own thing too.
### Installing CMake
For best results, make sure CMake.exe is included in the Windows path; this is not always the case after installing it. To check, open a command window and enter the following command:
```console
cmake --version
```
If CMake is on the Windows path, this command will return the version of CMake you're using. Otherwise, it will say 'cmake' is not recognized as an internal or external command, operable program or batch file. If this is the case, you will have to [modify the PATH environment variable](https://www.computerhope.com/issues/ch000549.htm) for your account. You will not have to be an administrator if you only modify the PATH variable for *your* account. Add the folder location for the bin folder in your CMake installation folder. By default, the path will look something like `C:\Program Files\CMake\bin\`.
### Building with CMake
To build the projects with CMake, navigate to the root directory in the command window and issue the following commands:
```console
cmake -S . -B ./out
cmake --build ./out --config Debug
cmake --install ./out --prefix . --config Debug
```
1. The first line above runs what CMake calls the *configure* and *generate* steps.
2. The second line actually compiles and links your projects. We used the debug configuration, so you will find the compiled binaries in `./out/Debug/`. We just as easily could have built the release mode binaries by writing 'Release' instead of 'Debug' for the parameter value of the `--config` option.
3. The third line *installs* the projects into the root folder. This means the generated binary artifacts will all be copied into common folders (e.g. `bin` and `lib`). This is especially necessary in this case because the generated my_lib.dll file **must** be in the same folder as the generated mex_add_example.mexw64 file; otherwise you will get an error in Matlab saying something like 'could not load the required module'. This means your mex function couldn't find the DLL it's trying to link against.

The two generated files you need will be located in the `<project root>/bin` folder.
* mex_add_example.mexw64
* my_lib.dll
### Running in Matlab
Now that you have a .mexw64 file generated, Matlab can use it as a function as long as it is on the Matlab search path. The easiest way to test this is to cd into the `bin` folder which contains the generated mex_add_example.mexw64 file and invoke it with two doubles. The output will be the sum of the two numbers. If everything works, it should look like the below example:
```matlab
>>mex_add_example(1, 2)
ans =
     3
>>
```
If you run Matlab's addpath() function passing the `<project root>/bin` folder as the input, you will be able to access your generated mex function no matter which folder you are cd'd into.