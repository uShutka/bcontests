#include <iostream>
#include <vector>


int main() {
    int m, n;
    std::cin >> m >> n;

    int left = 1, right = m;
    std::vector<int> sequence(n);

    for (int i = 0; i < n; ++i) {
        std::cout << 1 << '\n';
        fflush(stdout); 
        int response;
        std::cin >> response;
        if (response == 0) {
            exit(0);
        }
        sequence[i] = response;
    }

    int current_query = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        std::cout << mid << '\n';
        fflush(stdout);

        int response;
        std::cin >> response;

        if (response == 0) {
            exit(0);
        }

        if (sequence[current_query % n] == 1) {
            if (response == 1) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        else {
            if (response == 1) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        current_query++;
    }

    return 0;
}
