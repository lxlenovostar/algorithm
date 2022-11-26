#include <vector>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

class Solution {
private:
    struct item {
        int key1;
        int key2;

        item(int _key1, int _key2): key1(_key1), key2(_key2) {}

        bool operator <(const item& rhs) const {
            return (key1 + key2) < (rhs.key1 + rhs.key2); 
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        std::priority_queue<struct item> m_queue;
        vector<vector<int>> ret;

        for (const auto& key1: nums1) {
            for (const auto& key2: nums2) {
                struct item new_item(key1, key2);

                m_queue.push(new_item);

                std::cout << "key1: " << key1 << " key2: " << key2 << std::endl;

                if (m_queue.size() > k) {
                    m_queue.pop();
                }
            }
        }


        while (!m_queue.empty()) {
            const auto& val = m_queue.top();
            vector<int> ret_val = {val.key1, val.key2};
            ret.push_back(ret_val);
            m_queue.pop();
        }

        return ret;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 */
int main() {
    vector<int> nums1 = {1,7,11}; 
    vector<int> nums2 = {2,4,6}; 
    int k = 3;
    Solution *test = new Solution();
    for (const auto& item: test->kSmallestPairs(nums1, nums2, k)) {
        for (const auto& val: item) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}