#include <vector>
#include <iostream>
#include <set>
using namespace std;

// 哈希
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;

        set<int> check_set;
        set<int> checked_set;
        for (auto item : nums) {
            check_set.insert(item);
        }

        for (auto item : nums) {
            if (check_set.find(item-1) != check_set.end()) {
                continue;
            } else {
                if (checked_set.find(item) != checked_set.end())
                    continue;

                int tmp_longest = 0;
                int index = 1;
                while(true) {
                    tmp_longest++;

                    if (check_set.find(item+index) == check_set.end()) {
                        break;
                    } else {
                        index++;
                    }
                }
                longest = std::max(longest, tmp_longest);
                checked_set.insert(item);
           } 
        }

        return longest;
    }
};

int main() {
    vector<int> nums = {100,4,200,1,3,2};
    Solution *test = new Solution();
    std::cout << test->longestConsecutive(nums) << std::endl;
    return 0;
}