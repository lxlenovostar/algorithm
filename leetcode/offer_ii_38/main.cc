#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret;
        stack<int> s; // index 入栈
        ret.resize(temperatures.size(), 0);
        s.push(0);

        for (int i = 1; i < temperatures.size(); ++i) {
            int cur = i;
            while (s.size() > 0 && temperatures[cur] > temperatures[s.top()]) {
                ret[s.top()] = cur - s.top();
                //std::cout << "what1 top: " << s.top() << std::endl;
                s.pop();
            }
            //std::cout << "what2 push: " << cur << std::endl;
            //std::cout << "what3 push: " << i << std::endl;
            s.push(cur);
        }

        return ret;
    }
};

int main() {
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    //vector<int> temperatures = {30, 60, 90};

    Solution *test = new Solution();
    for (const auto& item: test->dailyTemperatures(temperatures)) {
        std::cout << item << std::endl;
    }

    return 0;
}