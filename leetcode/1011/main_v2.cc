#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
    
        int left = *(std::max_element(weights.begin(), weights.end()));
        int right = std::accumulate(weights.begin(), weights.end(), 0);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            std::cout << "mid: " << mid << " right: " << right << " left: " << left << std::endl;
            if (check_weights(weights, days, mid)) {
                right = mid-1;
                std::cout << "right: " << right << std::endl;
            } else {
                left = mid+1;
                std::cout << "left: " << left << std::endl;
            }
        }

        return left;
    }
private:
    bool check_weights(vector<int>& weights, int days, int cap) {
        int sum_weights = 0;
        int sum_days = 1;
        for (int i = 0; i < weights.size(); ++i) {
            sum_weights += weights[i];
            if (sum_weights > cap) {
                sum_days += 1;
                if (sum_days > days)
                    return false;
                sum_weights = weights[i];
            }
        }

        return sum_days <= days ? true : false;
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