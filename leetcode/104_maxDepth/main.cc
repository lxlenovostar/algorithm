/*
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
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
	private: 
	int max_depth;

	void recursive(TreeNode* node, int level) {
		if (node == NULL) {
			if (level >= max_depth) {
				std::cout << "level: " << level <<  " max_depth: " << max_depth << std::endl;
				max_depth = level;
			}
			return;
		}

		std::cout << "val: " << node->val << " level: " << level << std::endl;

		++level;

		recursive(node->left, level);
		recursive(node->right, level);

	}
	
	public:
    int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;

		recursive(root, 0);

		return max_depth;
	}

	

};

int  main() {
	/*
	TreeNode *a1 = new TreeNode(3);
	TreeNode *a2 = new TreeNode(9);
	TreeNode *a3 = new TreeNode(20);
	TreeNode *a4 = new TreeNode(15);
	TreeNode *a5 = new TreeNode(7);

	a1->left = a2;
	a1->right = a3;
	a3->left = a4;
	a3->right = a5;
	*/
	
	TreeNode *a1 = new TreeNode(1);
	TreeNode *a2 = new TreeNode(2);
	a1->left = a2;

	Solution *test = new Solution();
	int result = test->maxDepth(a1);	
	std::cout << "result:" <<  result << std::endl;

	return 0;	

}

