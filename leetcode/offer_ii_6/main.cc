#include <map>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::map<int, int> check_map;
        std::vector<int> ret;

        for (size_t index = 0; index < numbers.size(); ++index) {
            check_map[numbers[index]] = index;
        }
        
        for (size_t index = 0; index < numbers.size(); ++index) {
            int delta = target - numbers[index];
            if (check_map.find(delta) != check_map.end()) {
                int delta_index = check_map[delta];
                if (delta_index >= index) {
                    ret.push_back(index);
                    ret.push_back(delta_index);
                } else {
                    ret.push_back(delta_index);
                    ret.push_back(index);
                }

                return ret; 
            }
        }

        return ret;
    }
};

int main() {
    vector<int> numbers = {1,2,4,6,10};
    int target = 8;

    Solution *test = new Solution();
    const auto& vals = test->twoSum(numbers, target);
    for (const auto& val: vals) {
        std::cout << val << std::endl;
    }
    return 0;
}