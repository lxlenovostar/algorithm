#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:

    void helper(int left, int right, std::string extension, vector<string>& result) {
        if (left == 0 && right == 0) {
            result.push_back(extension);
        } else {
            if (left > 0) {
                helper(left-1, right, extension+"(", result);
            }

            if (left < right)
                helper(left, right-1, extension+")", result);

        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        helper(n, n, "", ret);
        return ret;
    }
};

int main() {
    Solution *test = new Solution();
    int n = 3;
    for (const auto& item: test->generateParenthesis(n)) {
        std::cout << item << " " << std::endl;
    }
    return 0;
}