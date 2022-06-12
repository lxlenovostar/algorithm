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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode*> index;

        if (root == nullptr) {
            return ret;
        }
        
        index.push(root);

        while (index.size() != 0) {
            TreeNode *node = index.front();
            ret.emplace_back(node->val);
            index.pop();
            if (node->left) 
                index.push(node->left);
            if (node->right) 
                index.push(node->right);

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
    for (const auto& item : test->levelOrder(a1))
        std::cout << item << std::endl;
    return 0;
}
