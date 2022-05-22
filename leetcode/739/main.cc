#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        size_t len = temperatures.size();
        vector<int> ret(len);

        //std::cout << "len: " << len << std::endl;
        for (int i = len - 1; i >= 0; --i) {
            //std::cout << "i: " << i << std::endl;
            while(!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }
            ret[i] = s.empty() ? 0 : (s.top() - i);
            s.push(i);
        }


        std::cout << "ret.size " << ret.size() << std::endl;
        return ret;
    }
};

int main()
{
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    Solution *test = new Solution();

    for (const auto & item : test->dailyTemperatures(temperatures)) {
        std::cout << item << std::endl;
    }

    return 0;
}