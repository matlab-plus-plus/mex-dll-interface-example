# Subproject which generates the .dll output, and provides
# the .dll library target for linking the mex function against.

cmake_minimum_required(VERSION 3.22)

project(mylib VERSION 1.0.0 LANGUAGES CXX)

add_library(my_lib SHARED)

# The include directory must be public so other targets
# include it also.
target_include_directories(my_lib
	PUBLIC ./inc
)

# The header must be public so other projects consuming
# this library will include it also.
target_sources(my_lib
	PUBLIC ./inc/mylib.hpp
	PRIVATE ./src/mylib.cpp
)

# Add the EXPORTING_ macro definition because it will
# trigger the library to export the symbols in this case
# in the header. Including the header without defining
# the macro will cause the symbols to be imported.
#
# NOTE: This **must** be private, otherwise targets linking
#       against this will also define the EXPORTING_ macro.
target_compile_definitions(my_lib
	PRIVATE _EXPORTING
)

# Install the output files into bin and lib folders which
# code using this library should also install into. This
# ensures, for example, that the generated .dll file is
# copied into the same directory as the binary of the file
# loading it, and therefore, that Windows will be able to
# find it when the main application loads.
install(TARGETS my_lib)