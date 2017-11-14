/* 
 * 112 Path Sum
 *
 * Given a binary tree and a sum, determine if the tree has 
 * a root-to-leaf path such that adding up all the values along 
 * the path equals the given sum.
 * */

#include <iostream>
#include <assert.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
	public:
		bool checksum(TreeNode *node, int num) 
		{
			if (node == NULL && num == 0)
				return true;


		}

		bool hasPathSum(TreeNode* root, int sum) {
			bool result_left;
			bool result_right;
			if (root == NULL)
				return false;

			if (root->val == sum && (root->left == NULL || root->right == NULL))
				return true;

			if (root->left != NULL)
				result_left = checksum(root->left, sum - root->val);
			
			if (root->right != NULL)
				result_right = checksum(root->right, sum - root->val);

			if (result_left || result_right)
				return true;
			else 
				return false;
		}


};

int  main() {
	TreeNode *a5 = new TreeNode(5);
	TreeNode *a4 = new TreeNode(4);
	TreeNode *a8 = new TreeNode(8);
	TreeNode *a11 = new TreeNode(11);
	TreeNode *a13 = new TreeNode(13);
	TreeNode *a42 = new TreeNode(4);
	TreeNode *a7 = new TreeNode(7);
	TreeNode *a2 = new TreeNode(2);
	TreeNode *a1 = new TreeNode(1);

	a5->left = a4;
	a5->right = a8;
	a4->left = a11;
	a8->left = a13; 
	a8->right = a42;
	a11->left = a7;
	a11->right = a2;
	a42->right = a1;

	Solution *test = new Solution();
	bool result = test->hasPathSum(a5, 22);	
	std::cout << "result:" <<  result << std::endl;

	return 0;	
}
