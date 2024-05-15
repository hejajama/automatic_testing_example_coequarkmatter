#include <iostream>
#include <gsl/gsl_integration.h>
#include <cmath>
#include "wave_function.hpp"

using namespace std;

// This program computes <x> and <x^2> for a quantum mechanical particle in 
// an infinite square well potential.
// Potential is 0 form x=0 to x=a, inf everywhere else

struct inthelper {
    int n; // Energy level: E = n^2 hbar^2/(8ma^2)
    int power; // We integrate \Psi^2 * x^power
    double a; // width of the well
};

double integrand(double x, void* params) {
    inthelper *par = (inthelper*)params;

    return std::pow(x,par->power) * wave_function(x, par->n, par->a) * wave_function(x, par->n, par->a);
}

int main() {
    // Set up GSL integration workspace
    gsl_integration_workspace* workspace = gsl_integration_workspace_alloc(1000);

    // Set up integration parameters
    inthelper helper;
    helper.n=2;
    helper.power=1; // compute first <x>
    helper.a=10; // size
    gsl_function F;
    F.function = &integrand;
    F.params = &helper;

    // Perform the integration
    double result, error;
     
    gsl_integration_qags(&F, 0, helper.a, 0, 1e-4, 1000, workspace, &result, &error);
    cout << "<x> =  " << result << " +/- " << error << endl;  

    // then <x^2>
    helper.power=2;
    gsl_integration_qags(&F, 0, helper.a, 0, 1e-4, 1000, workspace, &result, &error);
    cout << "<x^2> =  " << result << " +/- " << error << endl;  

    // Clean up
    gsl_integration_workspace_free(workspace);

    return 0;
}