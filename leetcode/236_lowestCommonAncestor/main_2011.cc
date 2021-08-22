
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <iostream>

class Solution {
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			if (root == nullptr || root == p || root == q) return root;

			TreeNode *left = lowestCommonAncestor(root->left, p, q);
		    TreeNode *right	= lowestCommonAncestor(root->right, p, q);

			return left == nullptr ? right : right == nullptr ? left : root;

		}
};

int  main() {
	
	TreeNode *a1 = new TreeNode(3);
	TreeNode *a2 = new TreeNode(5);
	TreeNode *a3 = new TreeNode(1);
	TreeNode *a4 = new TreeNode(6);
	TreeNode *a5 = new TreeNode(2);
	TreeNode *a6 = new TreeNode(0);
	TreeNode *a7 = new TreeNode(8);
	TreeNode *a8 = new TreeNode(7);
	TreeNode *a9 = new TreeNode(4);

	a1->left = a2;
	a1->right = a3;

	a2->left = a4;
	a2->right = a5;

	a5->left = a8;
	a5->right = a9;

	a3->left = a6;
	a3->right = a7;
	
	Solution *obj = new Solution();
	//TreeNode *node = obj->lowestCommonAncestor(a1, a2, a3);	
	TreeNode *node = obj->lowestCommonAncestor(a1, a2, a9);	
	if (node != nullptr)
		std::cout << "result:" <<  node->val << std::endl;

	return 0;	

}

