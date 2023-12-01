#include <iostream>
#include <cmath>

// Define the original function f(x)
double originalFunction(double x) {
    return x * x * x+ 4*x+8;
}

// Define a function to calculate the derivative of f(x) at a specific point x
double calculateDerivative(double (*f)(double), double x, double h = 1e-5) {
    double dx = h;
    double f_x = f(x);
    double f_x_plus_h = f(x + h);

    return (f_x_plus_h - f_x) / dx;
}

int main() {
    double x;

    // Prompt the user for input
    std::cout << "Enter a value for x: ";
    
    // Receive user input
    std::cin >> x;

    // Calculate the derivative
    double result = calculateDerivative(originalFunction, x);

    // Display the result
    std::cout << "The derivative of f(x) = " << x << " is approximately: " << result << std::endl;

    return 0;
}
