


#include "combinatorics.hpp"

// This file don't work. Just cause segfault. Stupid netcode.
// Would use arbitrary precision but can just plug in wolfram alpha instead.


// Modified from https://www.tutorialspoint.com/cplusplus-program-to-compute-combinations-using-factorials
double factorial(double n) {
    double out = 1;
    for (double i = 1; i <= n; ++i) {
        out *= i;
    }
    return out;
}

double count_combinations(double n, double r) {
    return (factorial(n) / (factorial(r) * factorial(n - r)));
}

double count_combinations_between_k(double n, double k1, double k2) {
    double out = 0;
    for (int i = k1; i < k2; i++) {
        out += count_combinations(n, i);
    }
    return out;
}
