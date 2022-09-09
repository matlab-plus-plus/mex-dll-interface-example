/*
* Library implementation
*/
#include "mylib.hpp"

CLASS_DECLSPEC double C_CALL_CONVENTION addnums(double const LHS, double const RHS)
{
	return LHS + RHS;
}