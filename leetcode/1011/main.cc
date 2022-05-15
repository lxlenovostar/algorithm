#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(vector<int>& weights, int days, int cap) {
        int count_days = 1;
        int count_caps = 0;
        for (const auto & w: weights) {
                if (count_caps + w > cap) {
                    count_days += 1;
                    count_caps = w;
                } else {
                    count_caps += w;
                }
        }
        
        std::cout << "days: " << days << " count_days: " << count_days << " cap: " << cap << std::endl;

        if (count_days <= days)
            return true;
        else    
            return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
    
        int left = *(std::max_element(weights.begin(), weights.end()));
        int right = std::accumulate(weights.begin(), weights.end(), 0);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            std::cout << "mid: " << mid << " right: " << right << " left: " << left << std::endl;
            if (check(weights, days, mid)) {
                right = mid-1;
                std::cout << "right: " << right << std::endl;
            } else {
                left = mid+1;
                std::cout << "left: " << left << std::endl;
            }
        }

        return left;
    }
};

int main() {
    //vector<int> nums = {-1,0,3,5,9,12};
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    //vector<int> nums = {1,2,3,1,1};
    //int days = 4;
    int days = 5;
    Solution *test = new Solution();
    std::cout << test->shipWithinDays(nums, days) << std::endl;
    return 0;
}