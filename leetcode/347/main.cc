#include <vector>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct Event {
    int key;
    int val;
    Event(int x, int y) : key(x), val(y) {}
    friend bool operator<(Event const& lhs, Event const& rhs) {
        return lhs.key > rhs.key;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int , int> handle_map;

        for (auto item: nums) {
            handle_map[item] += 1;
        }

        priority_queue<Event> ret_queue;

        for (auto it : handle_map) {
            struct  Event  node = {it.second, it.first};
            ret_queue.push(node);

            if (ret_queue.size() > k) {
                ret_queue.pop();
            }
        }

        vector<int> ret;
        while(! ret_queue.empty()) {
            ret.push_back(ret_queue.top().val);
            ret_queue.pop();
        }

        return ret;
    }
};

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution *test = new Solution();

    for (auto item: test->topKFrequent(nums, k)) {
        std::cout << item << std::endl; 
    }    

    return 0;
}