#include <concepts>
#include <cstdint>
#include <print>
#include <string>
#include <sys/stat.h>
#include <vcruntime_typeinfo.h>
#include <vector>

template <typename T>
    requires std::integral<T> || std::floating_point<T>
class QuickSorter {
    using index = int64_t;

    static std::vector<T> insertion_sort(const std::vector<T>& array) {
        std::vector<T> arr = array;
        for (index i = 1; i < arr.size(); ++i) {
            T key = arr[i];
            index j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j -= 1;
            }
            arr[j + 1] = key;
        }
        return arr;
    }

    static T get_median_pivot(const std::vector<T>& array) {
        index low = 0;
        index high = static_cast<index>(array.size()) - 1;
        index mid = (high - low) / 2;
        const T& a = array[low];
        const T& b = array[mid];
        const T& c = array[high];
        // return the median of a, b, c using explicit comparisons
        if ((a < b && b < c) || (c < b && b < a)) {
            return b;
        }
        if ((b < a && a < c) || (c < a && a < b)) {
            return a;
        }
        return c;
    }
};

namespace {
template <typename T>
    requires std::integral<T> || std::floating_point<T>
std::vector<T> my_quick_sort(const std::vector<T>& array) {
    return QuickSorter<T>::sort(array);
}
} // namespace

int main() {
    std::vector<int> input{5, 6, 2, 1, 7, 3, 5, 7, 0};
    std::print("Hello");
}
