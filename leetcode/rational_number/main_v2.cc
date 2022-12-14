#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

//这个是求最大公因数咯 
int gcd(long long int p, long long int q)
{
	if (p%q == 0)
		return q;
	else
		return gcd(q, p%q);	
}
 
 
int main()
{
	long sum_a = 0; 
	long sum_b = 1;
	int m = 0;
	vector<std::pair<int, int>> nums;
	nums.push_back(std::make_pair(1, 2));
	nums.push_back(std::make_pair(1, 2));

	for (const auto& item: nums) {
		int up_num = item.first;			
		int down_num = item.second;			
		sum_a *= down_num;    
		sum_a += sum_b*up_num;
		sum_b *= down_num;
		m = gcd(sum_a, sum_b);
		sum_a = sum_a/m;
		sum_b = sum_b/m;
	}

	if (sum_a%sum_b == 0) {
		std::cout << sum_a/sum_b << std::endl;
	} else {
		std::cout << sum_a/sum_b << std::endl;
		std::cout << sum_a%sum_b << std::endl;
		std::cout << sum_b << std::endl;
	}


	return 0;
}