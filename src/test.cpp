#include "unit_test_framework.hpp"
#include "wave_function.hpp"
#include <gsl/gsl_integration.h>
#include <iostream> 

// The code assumes that wave functions are normalized. 
// This test checks that normalization condition \int |\Psi|^2 = 1
// is satsified

TEST(wave_function_normalization)
{
    // Define the integration workspace
    gsl_integration_workspace* workspace = gsl_integration_workspace_alloc(1000);

    // Define the integration result
    double result, error;

    // Perform the integration
    gsl_function F;
    F.function = [](double x, void* params) {
        int n=2; double a=10; // energy level and well width used in this test
        return wave_function(x,n,a)*wave_function(x,n,a);
    };
    gsl_integration_qags(&F, 0,10, 0, 1e-7, 1000, workspace, &result, &error); 
    // note: integrating only up to 10, modify if well is wider

    // Check the normalization condition
    ASSERT_ALMOST_EQUAL(result, 1.0, 1e-7);

}

TEST(wave_function_vanishes_outside_well)
{
    // Check that the wave function vanishes outside the well
    ASSERT_EQUAL(wave_function(-1,2,10), 0);
    ASSERT_EQUAL(wave_function(11,2,10), 0);
}

// DO NOT REMOVE
// Generates a main() function that runs all of your tests.
// Note: Some versions of g++ incorrectly produce a warning about empty
// statements when using the -pedantic flag. Therefore, we will not put
// a semicolon after the TEST_MAIN() macro.
TEST_MAIN()
