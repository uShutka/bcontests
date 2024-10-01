#include <iostream>
#include <algorithm>


long long count_less_equal(long long x, long long n, long long m) {
    long long count = 0;
    for (long long i = 1; i <= n; ++i) {
        count += std::min(m, x / i);
    }
    return count;
}

int main() {
    long long n, m, k;
    std::cin >> n >> m >> k;

    long long left = 1, right = n * m, result = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (count_less_equal(mid, n, m) >= k) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    std::cout << result;
    return 0;
}
