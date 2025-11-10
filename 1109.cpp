#include <iostream>
#include <print>

int main() {
    double i;
    // std::cout << i; // ERROR: Variable 'i' is uninitialized when used  here
    std::print("{}", i); // PASSED: Not even a warning ?!
    std::print("\nHello World!");
}
