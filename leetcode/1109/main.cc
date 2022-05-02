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

    vector<int> get_vector() {
        vector<int> ret;
        ret.resize(diff_nums.size());

        ret[0] = diff_nums[0];
        for (int i = 1; i < ret.size(); ++i) {
            ret[i] = ret[i-1] + diff_nums[i];
        }

        return ret;
    } 

    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        diff_nums.resize(n);

        for (const auto & booking : bookings) {
            int start = booking[0];
            int end = booking[1];
            int count = booking[2];

            update_diff(start-1, end-1, count);
        }
    
        return get_vector(); 
    }

private:
    vector<int> diff_nums;
};

int main() {
    vector<vector<int>> bookings ={{1,2,10}, {2,3,20}, {2,5,25}};
    int n = 5;

    Solution *test = new Solution();
    const auto & ret = test->corpFlightBookings(bookings, n);
    for (const auto & item : ret) 
        std::cout << item << std::endl;
    return 0;
}