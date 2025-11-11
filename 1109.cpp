#include <iostream>
#include <print>

int main() {
    bool iii;
    // std::cout << i; // ERROR: Variable 'i' is uninitialized when used  here
    std::print("{}", iii); // PASSED: Not even a warning ?!
    if (iii == true) {     // 冗余的布尔比较
                           // 应改为：if (x)
        std::print("\nHello");
    }
    std::print("\nWorld!");
}
