#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int largestRectangleArea1(vector<int>& heights) {
        int max_area = 0;
        for (size_t i = 0; i < heights.size(); ++i) {
            int min_height = heights[i];
            for (size_t j = i; j < heights.size(); ++j) {
                int width = j - i + 1;
                min_height = std::min(min_height, heights[j]); 
                max_area = std::max(max_area, width*min_height);
            }
        }

        return max_area;
    }
    
    int largestRectangleArea2(vector<int>& heights) {
        return helper(heights, 0, heights.size()-1);
    }
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> tmp_stack;
        tmp_stack.push(-1);

        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
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
private:
    int helper(vector<int>& heights, int begin, int end) {
        if (begin > end)
            return 0;

        if (begin == end)
            return heights[begin];
        
        int width = end - begin + 1;
        int min_index = begin;
        for (int i = begin+1; i <= end; i++) {
            if (heights[i] < heights[min_index])
                min_index = i; 
        }
        int max_area = width*heights[min_index];
        std::cout << "max_area: " << max_area << " begin: " << begin << " end: " << end << " min_index: " << min_index << std::endl;
        int left_max = helper(heights, begin, min_index-1);
        int right_max = helper(heights, min_index+1, end);

        max_area = std::max(max_area, left_max);
        return std::max(max_area, right_max);
    }
};

int main() {
    //vector<int> heights = {2, 1, 5, 6, 2, 3};
    vector<int> heights = {4, 2};
    //vector<int> heights = {1, 1};

    Solution *test = new Solution();
    std::cout << "ret: " << test->largestRectangleArea(heights) << std::endl;

    return 0;
}