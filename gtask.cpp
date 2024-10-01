#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> v(n), w(n);

    for (int i = 0; i < n; ++i) std::cin >> v[i] >> w[i];

    double left = 0, right = 1e9, mid;

    while (right - left > 1e-6) {
        mid = (left + right) / 2;
        std::vector<double> a(n);

        for (int i = 0; i < n; ++i) {
            a[i] = v[i] - mid * w[i];
        }

        sort(a.rbegin(), a.rend());

        double summ = 0;
        for (int i = 0; i < k; ++i) {
            summ += a[i];
        }

        if (summ >= 0) {
            left = mid;
        }
        else {
            right = mid;
        }
    }

    std::vector<std::pair<double, int>> res(n);

    for (int i = 0; i < n; ++i) {
        res[i] = { v[i] - left * w[i], i + 1 };
    }

    std::sort(res.rbegin(), res.rend());

    for (int i = 0; i < k; ++i) {
        std::cout << res[i].second << ' ';
    }

    return 0;
}
