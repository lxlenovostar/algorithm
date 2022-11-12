#include <stack>
#include <vector>
#include <iostream>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> ret;    
        ret.resize(nums1.size());
        std::stack<int> bigger_one;
        std::map<int, int> finder;

        for (int i = nums2.size()-1; i >= 0; --i) {
            while (!bigger_one.empty() && bigger_one.top() < nums2[i]) {
                bigger_one.pop();
            }

            finder[nums2[i]] = bigger_one.empty() ? -1: bigger_one.top();
            bigger_one.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); ++i) {
            ret[i] = finder[nums1[i]];
        }

        return ret;
    }
};

int main()
{
    //vector<int >nums1 = {4,1,2};
    vector<int >nums1 = {2,4};
    //vector<int >nums1 = {1,3,5,2,4};
    //vector<int> nums2 = {1,3,4,2};
    //vector<int> nums2 = {6,5,4,3,2,1,7};
    vector<int> nums2 = {1,2,3,4};
    Solution *test = new Solution();

    for (const auto & item : test->nextGreaterElement(nums1, nums2)) {
        std::cout << item << std::endl;
    }

    return 0;
}