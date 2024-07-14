#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (k > nums.size())
            return -1;
        
        for (auto item : nums) {
            m_priority.push(item);
        }

        while(k-1>0) {
            //std::cout << "top: " << m_priority.top() << std::endl;
            m_priority.pop();
            k--;
        }

        return m_priority.top();
    }
private:
    priority_queue<int> m_priority;
};

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    Solution *test = new Solution();
    std::cout << "ret: " << test->findKthLargest(nums, k) << std::endl;

    return 0;
}