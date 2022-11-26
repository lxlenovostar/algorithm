#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class KthLargest {
private:
    std::priority_queue<int, vector<int>, std::greater<int>> m_queue;
    //std::priority_queue<int, vector<int>, std::less<int>> m_queue;
    int m_cap;

public:
    KthLargest(int k, vector<int>& nums) {
        m_cap = k;

        for (const auto& item: nums) {
            add(item);           
        }
    }
    
    int add(int val) {
        m_queue.push(val);

        if (m_queue.size() > m_cap) {
            m_queue.pop();
        }

        std::cout << "what: " << m_queue.top() << std::endl;

        return m_queue.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 */
int main() {
    int k = 3;
    vector<int> nums = {4, 5, 8, 2};
    KthLargest* obj = new KthLargest(k, nums);
    int val = 3;
    int param_1 = obj->add(val);
    std::cout << param_1 << std::endl;
    val = 5;
    param_1 = obj->add(val);
    std::cout << param_1 << std::endl;

    return 0;
}