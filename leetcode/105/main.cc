#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (size_t i = 0; i < inorder.size(); ++i) {
            index[inorder[i]] = i;
        }

        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);    
    }
private:
    TreeNode* helper(vector<int> preorder, vector<int> inorder, int pre_left, int pre_right, int in_left, int in_right) {
        if (pre_left > pre_right || in_left > in_right)
            return nullptr;
        

        int root_val = preorder[pre_left];
        struct TreeNode *node = new TreeNode(root_val);
        int pos = index[root_val];

        node->left = helper(preorder, inorder, pre_left+1, pos-in_left+pre_left, in_left, pos -1);
        node->right = helper(preorder, inorder, pos-in_left+pre_left+1, pre_right, pos + 1, in_right);

        return node;
    }
private:
    unordered_map<int, int> index;
};

int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Solution *test = new Solution();
    test->buildTree(preorder, inorder); 

    return 0;
}