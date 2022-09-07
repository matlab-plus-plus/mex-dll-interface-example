/*
* mylib is a simple library that will be generated into a shared .dll
* 
* All it does is add two doubles together.
*/

#pragma once

// Macros defined for readability and reusability

// Recommended by https://docs.microsoft.com/en-us/cpp/build/importing-into-an-application-using-declspec-dllimport?view=msvc-170
#ifdef _EXPORTING
	// Exporting the symbol. Only the library project should have
	// this defined, so only the libary will export it. Everything
	// else using this header file will import it.
	#define CLASS_DECLSPEC    __declspec(dllexport)
#else
	// Importing the symbol
	#define CLASS_DECLSPEC    __declspec(dllimport)
#endif

#define C_CALL_CONVENTION __cdecl


CLASS_DECLSPEC double C_CALL_CONVENTION addnums(double const, double const);