#include <iostream>
#include <climits>

class Solution {
	public:
		/*
		double myPow(double x, int n) {
			if (n == 0)
				return 1;

			double ret = 1;
			unsigned int m = n > 0 ? n : (0 - n);
			for (unsigned int i = 1; i <= m; ++i) {
				ret *= x;	
			}

			std::cout << "n: " << n << " ret: " << ret << std::endl;

			if (n > 0)
				return ret;
			else 
				return 1/ret;
		}
		*/

		/*
		double quickMul(double x, long long n) {
			if (n == 0) {
				return 1;
			}

			if (n == 1) {
				return x;
			}

			if (n < 0)
				return 1.0f/quickMul(x, -n);

			if (n%2)
				return x*quickMul(x, n-1);

			return quickMul(x*x, n/2);


		}

		//double myPow(double x, int n) {
		double myPow(double x, int n) {

			return quickMul(x, n);

		}
		*/
		
		double myPow(double x, int n) {
			long m = n;
			if (m < 0) {
				x = 1/x;
				m = 0 - m;
			}

			double pow = 1.0;
			while (m) {
					if (m&1)
						pow *= x;
					x *= x;	
					m >>= 1;
			}

			return pow;

		}
};

int main() {
	Solution *test = new Solution();
	//std::cout << test->myPow(2.0, 10) << std::endl;
	std::cout << test->myPow(1.0, -2147483648) << std::endl;
	//std::cout << test->myPow(2.1, 3) << std::endl;
	//std::cout << test->myPow(2.0, -2) << std::endl;
	return 0;
}
