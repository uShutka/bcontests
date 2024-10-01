#include <iostream>


long double getTrees(long long days, long long per_day1, long long rest1, long long per_day2, long long rest2) {
	return 1.0L * (days - days / rest1) * per_day1 + 1.0L * (days - days / rest2) * per_day2;
}


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	long double per_day1, rest1, per_day2, rest2, trees;
	std::cin >> per_day1 >> rest1 >> per_day2 >> rest2 >> trees;

	long long left = 0;
	long long right = trees;

	while (left + 1 < right) {
		long long mid = (left + right) / 2;
		if (getTrees(mid, per_day1, rest1, per_day2, rest2) < trees) {
			left = mid;
		}
		else {
			right = mid;
		}
	}

	std::cout << right;
	return 0;
}