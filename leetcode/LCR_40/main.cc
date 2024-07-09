#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<string>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        
        int maxArea = 0;
        vector<int> heights;
        heights.resize(matrix[0].size(), 0);
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    heights[j]++;
                }
            }

            maxArea = std::max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }

private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> tmp_stack;
        tmp_stack.push(-1);

        int maxArea = 0;
        for (size_t i = 0; i < heights.size(); ++i) {
            while (tmp_stack.top() != -1 && heights[tmp_stack.top()] >= heights[i])
            {
                int height = heights[tmp_stack.top()];
                tmp_stack.pop();
                int width = i - tmp_stack.top() - 1;
                maxArea = std::max(maxArea, height * width);   
            }

            tmp_stack.push(i);
        }

        while (tmp_stack.top() != -1) {
            int height = heights[tmp_stack.top()];
            tmp_stack.pop();
            int width = heights.size() - tmp_stack.top() - 1;
            maxArea = std::max(maxArea, height * width);   
        }

        return maxArea;
    }
};

int main() {
    //vector<string> matrix = {"10100","10111","11111","10010"};
    vector<string> matrix = {"10"};

    Solution *test = new Solution();
    std::cout << "ret: " << test->maximalRectangle(matrix) << std::endl;

    return 0;
}