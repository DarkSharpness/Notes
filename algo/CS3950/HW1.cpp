#include <span>
#include <iostream>

using value_t = int;
constexpr int N = 1 << 10;

size_t counter = 0;

// Compare two values.
bool cmp(value_t __a, value_t __b) {
    ++counter;
    return __a < __b;
}

struct answer_type {
    value_t lmin;
    value_t rmin;
    bool result;
} data[N];

// Return the unique index of a range.
size_t get_num(size_t __l, size_t __len) {
    return (__l + N) / __len - 1;
}

// Find the min and keep track of the result.
value_t find_min(value_t *__arr, size_t __l, size_t __len) {
    if (__len == 1) return __arr[__l];
    auto __r = __l + __len / 2;
    auto __a = find_min(__arr, __l, __len / 2);
    auto __b = find_min(__arr, __r, __len / 2);
    bool __cmp = cmp(__a, __b);
    // Store the result.
    data[get_num(__l, __len)] = {__a, __b, __cmp};
    return __cmp ? __a : __b;   
}

// Find the second min after finding min.
value_t find_sec(value_t *__arr, size_t __l, size_t __len) {
    auto [__a, __b, __cmp] = data[get_num(__l, __len)];
    // Special judge.
    if (__len == 2) return __cmp ? __b : __a;
    if (__cmp) { // Left min < Right min
        auto __c = find_sec(__arr, __l, __len / 2);
        return cmp(__c, __b) ? __c : __b;
    } else { // Left min > Right min
        auto __r = __l + __len / 2;
        auto __c = find_sec(__arr, __r, __len / 2);
        return cmp(__c, __a) ? __c : __a;
    }
}

void my_algorithm(value_t *__arr) {
    auto __min = find_min(__arr, 0, N);
    auto __sec = find_sec(__arr, 0, N);
    std::cout << "Min: " << __min << " Second: " << __sec << std::endl;
    std::cout << "Counter: " << counter << std::endl;
}

void brute_force(value_t *__arr) {
    value_t __min = INT_MAX;
    value_t __sec = INT_MAX;
    for (auto __val : std::span (__arr, N)) {
        if (__val < __min) {
            __sec = __min;
            __min = __val;
        } else if (__val < __sec) {
            __sec = __val;
        }
    }
    std::cout << "Min: " << __min << " Second: " << __sec << std::endl;
}


signed main() {
    srand(time(0));
    auto __arr = new value_t[N];
    for (auto &__val : std::span (__arr, N)) __val = rand();
    brute_force(__arr);
    my_algorithm(__arr);
    delete[] __arr;
    return 0;
}