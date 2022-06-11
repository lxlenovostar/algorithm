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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        bool ret = false;

        if (A != nullptr && B != nullptr) {
            if (A->val == B->val) {
                ret = CheckSubStructure(A, B);
            } 
            if (!ret) {
                ret = isSubStructure(A->left, B);
            } 
            if (!ret) {
                ret = isSubStructure(A->right, B);
            }
        }

        return ret;
    }

    bool CheckSubStructure(TreeNode* A, TreeNode* B) {

        if (B == nullptr) return true;

        if (A == nullptr) return false;

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
    std::cout << test->isSubStructure(a1, a1) << std::endl;
    return 0;
}
