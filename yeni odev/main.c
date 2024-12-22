#include <stdio.h>
#include <math.h>
 


// Define the function f(x) to differentiate
double f(double x) {
    return sin(x); // Example: f(x) = sin(x)
}

// Numerical derivative using 3h/8-based formula
double numerical_derivative_3h8(double (*func)(double), double x, double h) {
    // Using a 3/8-style coefficient scheme for higher-order accuracy
    // Formula: f'(x) ≈ (3/8 * f(x-h) - 3/8 * f(x+h)) / h
    double term1 = (3.0 / 8.0) * func(x - h);
    double term2 = -(3.0 / 8.0) * func(x + h);
    return (term1 + term2) / h;
}

int main() {
    double x = M_PI / 4; // Point where we compute f'(x) (example: π/4)
    double h = 0.01;     // Step size

    // Compute the numerical derivative
    double derivative = numerical_derivative_3h8(f, x, h);

    // Print the result
    printf("The numerical derivative of f(x) at x = %.4f is %.6f\n", x, derivative);

    // Exact derivative for comparison (for sin(x), f'(x) = cos(x))
    printf("The exact derivative at x = %.4f is %.6f\n", x, cos(x));

    return 0;
}
