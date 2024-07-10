#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea1(vector<int>& height) {
        int maxarea = 0;
        int len = height.size();

        for (int i = 0; i < len; ++i) {
            int left_height = height[i];
            for (int j = len-1; j > i; j--) {
                int right_height = height[j];
                int width = j - i;
                maxarea = std::max(maxarea, width*(std::min(left_height, right_height)));
            }
        } 

        return maxarea;
    }
    
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        int len = height.size();

        int left_index = 0;
        int right_index = len - 1;

        while (left_index < right_index) {
            int left_height = height[left_index];
            int right_height = height[right_index];
            int width = right_index - left_index;
            maxarea = std::max(maxarea, width*(std::min(left_height, right_height)));
            std::cout << "ret: left_height: " << left_height << " right_height: " << right_height << " maxarea: " << maxarea << std::endl;  

            if (left_height < right_height) {
                left_index++;
            } else {
                right_index--;
            }

        }

        return maxarea;
    }
};

int main() {
    vector<int> heights = {1,8,6,2,5,4,8,3,7};

    Solution *test = new Solution;
    std::cout << test->maxArea(heights) << std::endl;

    return 0;
}