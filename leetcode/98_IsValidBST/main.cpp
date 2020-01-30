/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
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

using namespace std;

class Solution {
public:
	long prev;

	bool dfs(TreeNode *node, int value, bool left) {
		if (node == nullptr)
			return true;
	
		std::cout << "left: " << left  << " val: " << node->val << std::endl;
		
		if (left) {
			if (node->val >= value) {
				std::cout << "what1" << std::endl;
				return false;	
			}
		} else { 
			if (node->val <= value) {
				std::cout << "what2" << std::endl;
				return false;	
			}
		}
		
		bool ret_left  =  dfs(node->left, node->val, true);
		if (ret_left == false) {
			std::cout << "what3" << std::endl;
			return false;
		}

		bool ret_right = dfs(node->right, node->val, false);
		if (ret_right == false) {
			std::cout << "what4" << std::endl;
			return false;
		}
		
		return true;
	}

	//wrong function
 	bool isValidBST_1(TreeNode* root) {
		if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
			return true;
		}
	
		bool ret_left  =  dfs(root->left, root->val, true);
		bool ret_right = dfs(root->right, root->val, false);

		return (ret_left && ret_right);
    }

	bool isValidBST_2(TreeNode *root) {
		if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
			return true;
		}

		return valid(root, numeric_limits<long>::min(), numeric_limits<long>::max());
	}

	bool valid(TreeNode *node, long minVal, long maxVal) {

		if (!node) {
			return true;
		}

		if (node->val <= minVal || node->val >= maxVal) {
			std::cout << "node->val: " << node->val << " minVal: " << minVal << " maxVal: " << maxVal << std::endl;
			return false;
		}

		return valid(node->left, minVal, node->val) && valid(node->right, node->val, maxVal); 
	
	}

	bool helper(TreeNode *node) {
		if (node == nullptr)
			return true;


		bool ret = helper(node->left);
		if (ret == false)
			return false;

		if (node->val > prev) 
			prev = node->val;
		else 
			return false;

		ret = helper(node->right);

		return ret;
	}

	//inorder
	bool isValidBST(TreeNode *root) {
		if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
			return true;
		}

		prev = numeric_limits<long>::min();

		return helper(root);
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

