#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void update_diff(int start, int end, int count) {
        diff_nums[start] += count;

        if ((end+1) < diff_nums.size())
            diff_nums[end+1] -= count;
    }

    bool get_ret() {
        vector<int> ret;
        ret.resize(diff_nums.size());

        ret[0] = diff_nums[0];
        for (int i = 1; i < ret.size(); ++i) {
            ret[i] = ret[i-1] + diff_nums[i];

            if (ret[i] > m_capacity) {
                std::cout << "i: " << i << " ret[i]: " << ret[i] << " m_capacity: " << m_capacity << std::endl;
                return false;
            }
        }

        return true;
    } 

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        m_capacity = capacity;
        diff_nums.resize(1001);

        for (const auto & item : trips) {
            int start = item[1];
            int end = item[2];
            int count = item[0];

            update_diff(start, end, count);
        }
    
        return get_ret(); 
 

    }

private:
    vector<int> diff_nums;
    int m_capacity;
};

int main() {
    vector<vector<int>> trips = {{2,1,5}, {3,3,7}}; 
    //vector<vector<int>> trips = {{2,1,5}, {3,5,7}}; 
    //vector<vector<int>> trips = {{9,0,1}, {3,3,7}}; 
    int capacity = 5;
    //int capacity = 3;
    //int capacity = 4;

    Solution *test = new Solution();
    std::cout << test->carPooling(trips, capacity) << std::endl;
    return 0;
}