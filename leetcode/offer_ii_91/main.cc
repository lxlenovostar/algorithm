#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();

        if (n <= 1) {
            return std::min(std::min(costs[0][1], costs[0][2]), costs[0][0]);
        }

        vector<int> r(n);
        vector<int> g(n);
        vector<int> b(n);

        r[0] = costs[0][0];
        g[0] = costs[0][1];
        b[0] = costs[0][2];
    
        for (int i = 1; i < n; ++i) {
            r[i] = costs[i][0] + std::min(g[i-1], b[i-1]);
            g[i] = costs[i][1] + std::min(r[i-1], b[i-1]);
            b[i] = costs[i][2] + std::min(r[i-1], g[i-1]);
        }

        return std::min(std::min(r[n-1], g[n-1]), b[n-1]);
    }
};

int main() {
    vector<vector<int>> costs = {{17,2,17}, {16,16,5}, {14,3,19}};
    Solution *test = new Solution();
    std::cout << test->minCost(costs) << std::endl;
    return 0;
}