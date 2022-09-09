Example setup for interacting with a generated .dll through Matlab with a Mex function.

This project walks you through the process of creating a mex function that loads a .dll file so that it can be interfaced with Matlab. This uses CMake as the build system generator and requires the following dependencies:
1. CMake version 3.22 or later
2. A C++ compiler capable of C++20 or later (Visual Studio 2019 is what I used)
3. Matlab version 9.8 (R2020a)
4. Windows 7 or later
### Installing CMake
For best results, make sure CMake.exe is included in the Windows path; this is not always the case after installing it. To check, open a command window and enter the following command:
```console
cmake --version
```
If CMake is on the windows path, this command will return the version of CMake you're using. Otherwise, it will say 'cmake' is not recognized as an internal or external command, operable program or batch file. If this is the case, you will have to [modify the PATH environment variable](https://www.computerhope.com/issues/ch000549.htm) for your account. You will not have to be an administrator if you only modify the PATH variable for *your* account. Add the folder location for the bin folder in your CMake installation folder. By default, the path will look something like `C:\Program Files\CMake\bin\`.
### Building with CMake
To build the projects with CMake, navigate to the root directory in the command window and issue the following commands:
```console
cmake -S . -B ./out
cmake --build ./out --config Debug
```
The first line above runs what CMake calls the *configure* and *generate* steps. The second line actually compiles and links your projects. We used the debug configuration, so you will find the compiled binaries in `./out/Debug/`. We just as easily could have built the release mode binaries by writing 'Release' instead of 'Debug' for the parameter value of the `--config` option.
### Running in Matlab
Now that you have a .mexw64 file generated, Matlab can use it as a function as long as it is on the Matlab search path. The easiest way to test this is to cd into the folder containing the generated mex_add_example.mexw64 file and invoke it with two doubles to add them together. If everything works, it should look like the below example
```matlab
>>mex_add_example(1, 2)
ans =
     3
>>
```