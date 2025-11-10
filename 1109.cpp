#include <concepts>
#include <print>
#include <vector>

template <typename Container>
concept has_direct_references = requires(Container& c) {
    { c[0] } -> std::same_as<typename Container::value_type&>;
};

int main() {
    static_assert(has_direct_references<std::vector<int>>);    // 通过 -> 正确！
    static_assert(has_direct_references<std::vector<double>>); // 通过 -> 正确！
    static_assert(has_direct_references<std::vector<char>>);   // 通过 -> 正确！
    static_assert(
        !has_direct_references<std::vector<bool>>); // 应不通过 -> 正确！
    std::print("\n\nHello world\n");
}
