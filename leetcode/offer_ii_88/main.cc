#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    int helper(vector<int>& cost, int index) {
        if (index <= 1)
            return cost[index];
        
        return std::min(helper(cost, index-1), helper(cost, index-2)) + cost[index];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        return std::min(helper(cost, n-1), helper(cost, n-2));
    }
};

int main() {
    vector<int> cost = {10, 15, 20};
    Solution *test = new Solution();
    std::cout << test->minCostClimbingStairs(cost) << std::endl;
    return 0;
}