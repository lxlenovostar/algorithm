#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {

        return check(postorder, 0, postorder.size());
    }

    bool check(vector<int>& postorder, int start, int end) {
        if (start >= end) return true;
        
        int root = postorder[end-1];

        //std::cout << "start: " << start << " end: " << end << std::endl;
        int index = start;
        for(; index < end-1; ++index) {
            if (postorder[index] > root) {
                //std::cout << "who " << index << " " << postorder[index]  << " " << root << std::endl;
                break;
            }
        }

        //std::cout << "index: " << index << " end: " << end << std::endl;
        for(int j = index; j < end-1; ++j) {
            if (postorder[j] < root) {
                //std::cout << "what " << j << " " << postorder[j]  << " " << root  << " end: " << end << std::endl;
                return false;
            }
        }
        return check(postorder, start, index) && check(postorder, index, end-1);
    }
};

int main() 
{
    vector<int> item = {1,3,2,6,5};
    Solution *test = new Solution();
    std::cout << test->verifyPostorder(item) << std::endl;
    return 0;
}
