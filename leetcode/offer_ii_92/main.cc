#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        if (n <= 1) {
            return 0;
        }

        vector<int> f(n);
        vector<int> g(n);

        if (s[0] == '0') {
            f[0] = 0;
            g[0] = 1;
        } else {
            f[0] = 1;
            g[0] = 0;
        } 

        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                f[i] = f[i-1]; 
                g[i] = std::min(g[i-1], f[i-1]) + 1;
            } else {
                f[i] = f[i-1] + 1; 
                g[i] = std::min(g[i-1], f[i-1]);
            }
        }

        return std::min(f[n-1], g[n-1]);
    }
};

int main() {
    std::string s = "00110";
    Solution *test = new Solution();
    std::cout << test->minFlipsMonoIncr(s) << std::endl;
    return 0;
}