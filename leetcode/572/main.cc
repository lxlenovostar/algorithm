#include <stdlib.h>
#include <iostream>
#include <vector>
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ret = false;

        if (root != nullptr && subRoot != nullptr) {
            if (root->val == subRoot->val) {
                ret = CheckSubStructure(root, subRoot);
            } 
            if (!ret) {
                ret = isSubtree(root->left, subRoot);
            } 
            if (!ret) {
                ret = isSubtree(root->right, subRoot);
            }
        }

        return ret;
    }

    bool CheckSubStructure(TreeNode* A, TreeNode* B) {

        if (A == nullptr && B == nullptr) return true;

        if (A == nullptr || B == nullptr) return false;

        if (A->val != B->val) 
            return false;

        return CheckSubStructure(A->left, B->left) && CheckSubStructure(A->right, B->right);

    }
};

int main() 
{
    TreeNode *a1 = new TreeNode(1);
	TreeNode *a2 = new TreeNode(2);
	TreeNode *a3 = new TreeNode(3);

	a1->right = a2;
	a2->left = a3;

    Solution *test = new Solution();
    std::cout << test->isSubtree(a1, a1) << std::endl;
    return 0;
}
