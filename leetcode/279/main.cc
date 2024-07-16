#include <vector> 
#include <iostream> 
#include <map>
using namespace std;

class Solution {
public:
    int numSquares(int n) {   
        vector<int> dp;
        dp.resize(n+1, 0);

        for (int i = 1; i <= n; ++i) {
            int min = INT_MAX;
            for (int j = 1;  j*j <= i; ++j) {
                min = std::min(min, dp[i - j*j]);
            }
            dp[i] = min + 1;
        }
        return dp[n];
    }

    int numSquares1(int n) {
        vector<int> dp;
        map<int, bool> check;
        dp.resize(n+1, n);
        dp[1] = 1;

        if (check_square(n))
            return 1;
        
        for (int i = 1; i <= n; i++) {
            if (check_square(i)) {
                dp[i] = 1;
                check[i] = true;
            } else {
                check[i] = false;
            }
        }

        for (int i = 1; i <= n; i++) {
            int min = n;
            for (int j = 1; j < i; j++) {
                //std::cout << "what0: i:" << i << " j: " << j << std::endl; 
                //if (check_square(j)) {
                //    dp[j] = 1;
                //}
                if (check[i - j]) {
                    if (check[j]) dp[j] = 1;
                    min = std::min(min, dp[j] + 1);
                    //std::cout << "what1 dp[" << i << "]:" << min << std::endl;; 
                }
            }
            dp[i] = min;
        }

        return dp[n];
    }
private:
    bool check_square(int k) {
        for (int i = 1; i <= k; ++i) {
            if (i*i == k)
                return true;
        }
        return false;
    }
};

int main() {
    int num = 5;
    Solution *test = new Solution();
    std::cout << test->numSquares(num) << std::endl;

    return 0;
}