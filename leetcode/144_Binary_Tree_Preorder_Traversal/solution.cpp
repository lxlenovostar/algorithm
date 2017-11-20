/* 
 * 144. Binary Tree Preorder Traversal 
 *
 * Given a binary tree and a sum, determine if the tree has 
 * a root-to-leaf path such that adding up all the values along 
 * the path equals the given sum.
 * */

#include <iostream>
#include <assert.h>

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
	public:
		vector<int> preorderTraversal(TreeNode* root) {
		}

};

int  main() {
	/*
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
	*/
	TreeNode *a1 = new TreeNode(1);
	TreeNode *a2 = new TreeNode(2);

	a1->left = a2;

	Solution *test = new Solution();
	bool result = test->hasPathSum(a1, 1);	
	std::cout << "result:" <<  result << std::endl;

	return 0;	
}
