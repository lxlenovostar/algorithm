#include <vector>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

class Solution {
private:
    struct item {
        int key;
        int count;

        item(int _key, int _count): key(_key), count(_count) {}

        bool operator <(const item& rhs) const {
            return count < rhs.count; 
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> m_map;
        std::priority_queue<struct item> m_queue;
        vector<int> ret;

        for (const auto& item: nums) {
            m_map[item] += 1;
        }

        for (const auto& val: m_map) {
            struct item new_item(val.first, val.second);          
            m_queue.push(new_item);
        }

        for (int i = 0; i < k; ++i) {
            if (!m_queue.empty()) {
                const auto& item = m_queue.top();
                ret.push_back(item.key);
                m_queue.pop();
            }
        }

        return ret;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 */
int main() {
    int k = 2;
    vector<int> nums = {1,1,1,2,2,3};
    Solution *test = new Solution();
    for (const auto& item: test->topKFrequent(nums, k))
        std::cout << item << std::endl;

    return 0;
}