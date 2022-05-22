#include <stack>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int len = nums.size();
        std::vector<int> ret(len);

        for (int i = 2*len - 1; i >= 0; --i) {
            //std::cout << "i: " << i << std::endl;
            while(!s.empty() && s.top() <= nums[i%len]) {
                s.pop();
            }
            ret[i%len] = s.empty() ? -1 : s.top();
            s.push(nums[i%len]);
        }

        //std::cout << "ret.size " << ret.size() << std::endl;
        return ret;
    }
};

int main()
{
    //vector<int >nums = {1,2,3,4,3};
    vector<int >nums = {1,2,1};
    Solution *test = new Solution();

    for (const auto & item : test->nextGreaterElements(nums)) {
        std::cout << item << std::endl;
    }

    return 0;
}