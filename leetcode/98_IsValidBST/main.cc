/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/

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

#include <string>
#include <iostream>
#include <iostream>
#include <limits>
#include <limits.h>

using namespace std;

class Solution {
	private:
		bool helper(TreeNode *node, long long_min, long long_max) {
			if (node == NULL)
				return true;

			if (node->val <= long_min || node->val >= long_max) {
				return false;
			}

			/*
			bool left_ret = helper(node->left, long_min, node->val);
			if (left_ret == false)
				return false;

			bool right_ret = helper(node->right, node->val, long_max);
			if (right_ret == false)
				return false;

			return true;
			*/

			return helper(node->left, long_min, node->val) && helper(node->right, node->val, long_max);
		}

	public:
    bool isValidBST(TreeNode* root) {

		return helper(root, LONG_MIN, LONG_MAX);

	}

};

int  main() {
	/*
	TreeNode *a1 = new TreeNode(5);
	TreeNode *a2 = new TreeNode(1);
	TreeNode *a3 = new TreeNode(4);
	TreeNode *a4 = new TreeNode(3);
	TreeNode *a5 = new TreeNode(6);

	a1->left = a2;
	a1->right = a3;
	a3->left = a4;
	a3->right = a5;
	*/
	
	TreeNode *a1 = new TreeNode(10);
	TreeNode *a2 = new TreeNode(5);
	TreeNode *a3 = new TreeNode(15);
	TreeNode *a4 = new TreeNode(6);
	TreeNode *a5 = new TreeNode(20);

	a1->left = a2;
	a1->right = a3;
	a3->left = a4;
	a3->right = a5;
	
	//TreeNode *a1 = new TreeNode(2147483647);

	/*
	TreeNode *a1 = new TreeNode(-2147483648);
	TreeNode *a3 = new TreeNode(2147483647);

	a1->right = a3;
	*/
	
	/*
	TreeNode *a1 = new TreeNode(2);
	TreeNode *a2 = new TreeNode(1);
	TreeNode *a3 = new TreeNode(3);
	a1->left = a2;
	a1->right = a3;
	*/
	
	//TreeNode *a1 = nullptr;
	//TreeNode *a1 = new TreeNode(2147483647);
	
	Solution *test = new Solution();
	bool result = test->isValidBST(a1);	
	std::cout << "result:" <<  result << std::endl;

	return 0;	

}

