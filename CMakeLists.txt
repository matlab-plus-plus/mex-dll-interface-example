# Require CMake version 3.22 or later because the FindMatlab
# module added the Matlab::mex imported target in this version.
cmake_minimum_required(VERSION 3.22)

project(MexLoadingDll VERSION 1.0.0 LANGUAGES CXX)

find_package(Matlab 9.8 EXACT
	REQUIRED MEX_COMPILER
)

# Add the 'DllSubproject' subdirectory to be configured.
#	This will create the 'my_lib' target which we can link against.
add_subdirectory(DllSubproject)

# Create mex target to build the mex function
set(CMAKE_IMPORT_LIBRARY_SUFFIX .dll)
matlab_add_mex(
	NAME mex_add_example
	SHARED
	R2018a
)

target_sources(mex_add_example
	PRIVATE ./src/mex_add_example.cpp
)

target_link_libraries(mex_add_example
	my_lib # Can't make this private, even though we would like to, because it must use the plain signature like the matlab_add_mex already does above (implicitly)
)

# Install the generated binaries into bin and lib directories
# so they will be in the same location as the my_lib library.
install(TARGETS mex_add_example)