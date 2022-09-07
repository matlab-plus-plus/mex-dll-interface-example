/*
* Mex function adding two doubles together.
*/
#include "mex.hpp"
#include "mexAdapter.hpp"
#include "MatlabDataArray.hpp"

#include "mylib.hpp" // This will import our addnum() function

using matlab::mex::ArgumentList;

class MexFunction : public matlab::mex::Function {
private:
    /* Any persistent state can be stored in private member varibles here. */
    matlab::data::ArrayFactory factory;
public:
    /* Constructor */
    MexFunction() = default;
    /* Operations to run during setup. */

    /* Destructor */
    ~MexFunction() = default;

    /* Function Operator */
    void operator()(ArgumentList outputs, ArgumentList inputs) {
        /*
        * The two input arguments are the doubles to be added.
        * The output is the sum of the two inputs.
        */

        double const LHS{ inputs[0][0] };
        double const RHS{ inputs[1][0] };

        outputs[0] = factory.createScalar<double>(
                addnums(LHS, RHS)
            );
    }
};