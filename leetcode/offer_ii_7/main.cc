#include <set>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rets;
        std::set<int> check_vals;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < (int)nums.size(); ++i) {
            int delta = 0 - nums[i];

            if (check_vals.find(nums[i]) == check_vals.end()) {
                check_vals.insert(nums[i]);
            } else {
                continue;
            }

            int begin = i+1;
            int end = nums.size() - 1;

            while (begin < end) {
                if (nums[begin] + nums[end] == delta) {
                    std::vector<int> ret = {nums[i], nums[begin], nums[end]};
                    rets.push_back(ret);
                    int last_begin_val = nums[begin];

                    begin++;
                    while(begin < end) {
                        if (nums[begin] == last_begin_val) {
                            begin++;
                        } else {
                            break;
                        }
                    }

                    continue;;
                }

                if (nums[begin] + nums[end] > delta) {
                    end--;
                    continue;
                }
                
                if (nums[begin] + nums[end] < delta) {
                    begin++;
                    continue;
                }

            }
        }

        return rets;
    }
};

int main() {
    //vector<int> numbers = {0, 0, 0, 0};
    //vector<int> numbers = {-1,0,1,2,-1,-4};
    vector<int> numbers = {0, 0, 0};

    Solution *test = new Solution();
    const auto& vals = test->threeSum(numbers);
    for (const auto& val: vals) {
        for (const auto& item: val) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}