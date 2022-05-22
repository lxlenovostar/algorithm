#include <stack>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        size_t len = nums2.size();
        std::map<int, int> ret_map;
        std::vector<int> ret(nums1.size());

        //std::cout << "len: " << len << std::endl;
        for (int i = len - 1; i >= 0; --i) {
            //std::cout << "i: " << i << std::endl;
            while(!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            ret_map[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }

        len = nums1.size();
        for (int i = len-1; i >= 0; --i) {
            ret[i] = ret_map[nums1[i]];
        }

        //std::cout << "ret.size " << ret.size() << std::endl;
        return ret;
    }
};

int main()
{
    vector<int >nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    Solution *test = new Solution();

    for (const auto & item : test->nextGreaterElement(nums1, nums2)) {
        std::cout << item << std::endl;
    }

    return 0;
}