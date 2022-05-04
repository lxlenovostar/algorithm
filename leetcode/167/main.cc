#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0; 
        int right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left+1, right+1};
            }
            if (sum > target) {
                right--;
            }
            if (sum < target) {
                left++;
            }
        }

        return {-1, -1};
    }
};

int main() {
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    Solution * test = new Solution();
    const vector<int> ret = test->twoSum(numbers, target);
    std::cout << ret[0] << std::endl;
    std::cout << ret[1] << std::endl;
}