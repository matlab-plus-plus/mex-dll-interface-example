# Require CMake version 3.22 or later because the FindMatlab
# module added the Matlab::mex imported target in this version.
cmake_minimum_required(VERSION 3.22)

project(MexLoadingDll VERSION 1.0.0 LANGUAGES CXX)

find_package(Matlab 9.8 EXACT
	REQUIRED MEX_COMPILER
)