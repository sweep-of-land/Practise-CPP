#include <iostream>
#include <ranges>
#include <vector>

class AutomaticDoor {
public:
    enum class State {
        cloased = 1,
        opening,
        open,
        closing,
    };

private:
    State state;
};

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};
    auto even_numbers =
        numbers | std::views::filter([](int n) { return n % 2 == 0; });
    std::cout << "Even numbers: ";
    for (const auto num : even_numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<bool> testor;

    return 0;
}
