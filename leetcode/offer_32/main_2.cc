#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/**
 * Definition for a binary tree node.
 */ 
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
    vector<vector<int>>  levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> index;

        if (root == nullptr) {
            return ret;
        }
        
        index.push(root);
        

        while (!index.empty()) {
            int size = index.size();

            ret.push_back(vector <int> ());
            for (int i = 0; i < size; ++i) {
                TreeNode* node = index.front(); 
                index.pop();
                ret.back().push_back(node->val);
                if (node->left) index.push(node->left);
                if (node->right) index.push(node->right);
            }
        }

        return ret;
    }
};

int main() 
{
    TreeNode *a1 = new TreeNode(3);
	TreeNode *a2 = new TreeNode(9);
	TreeNode *a3 = new TreeNode(20);
	TreeNode *a4 = new TreeNode(15);
	TreeNode *a5 = new TreeNode(7);

	a1->right = a2;
	a2->left = a3;

    a3->left = a4;
    a3->right = a5;

    Solution *test = new Solution();
    for (const auto& items : test->levelOrder(a1)) {
        for (const auto& item : items)
            std::cout << item << " ";
        std::cout << std::endl;
    }
    return 0;
}
