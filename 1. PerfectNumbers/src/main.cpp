#include <iostream>
#include <cmath>
#include <vector>

bool isPrime(size_t n)
{
	if (n <= 1)
		return false;
	for (size_t i = 2; i < n; i++)
		if (n % i == 0)
			return false;

	return true;
}

int main()
{
	size_t total = 0;
	long long sum = 0;
	for (size_t p = 2; p < 14; ++p) {
		if (isPrime(p)) {
			total = static_cast<size_t>((pow(2, p - 1)) * (pow(2, p) - 1));
			for (size_t divisor = 1; divisor <= total / 2; divisor++) {
				if (total % divisor == 0)
					sum += divisor;
			}
		}
		if (sum == total)
			std::cout << "Perfect number: " << total << std::endl;

		sum = 0;
	}

	return 0;
}