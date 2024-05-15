#include "wave_function.hpp"
#include <cmath>

using namespace std;


// Wave function for a particle in an infnite well
// Energy level quantum number is n
// Well width is a
double wave_function(double x, int n, double a){
    if (x < 0 or x > a) return 0;
    
    return sqrt(2/a) * sin(n * M_PI * x/a);
}
