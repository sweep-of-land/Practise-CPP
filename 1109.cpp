#include <concepts>
#include <print>
#include <vector>

// 概念1：检查容器是否有直接的引用（非代理）
template <typename Container>
concept has_direct_references = requires(Container& c) {
    { c[0] } -> std::same_as<typename Container::value_type&>;
};

int main() {
    // 测试各种容器
    static_assert(has_direct_references<std::vector<int>>);    // 通过
    static_assert(has_direct_references<std::vector<double>>); // 通过
    static_assert(has_direct_references<std::vector<char>>);   // 通过
    static_assert(!has_direct_references<std::vector<bool>>); // 不通过 - 正确！
    std::print("Hello world");
}
