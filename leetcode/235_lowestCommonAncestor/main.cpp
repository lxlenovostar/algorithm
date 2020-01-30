/*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

示例 1:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6
解释: 节点 2 和节点 8 的最近公共祖先是 6。
示例 2:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
 

说明:

所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉搜索树中。
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
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
	void dfs(TreeNode *root, TreeNode *node, vector<TreeNode*> &n_v) {
		if (root == nullptr)	
			return;

		if (root->val == node->val) {
			n_v.push_back(root);
			return;
		} else if (root->val < node->val) {
			n_v.push_back(root);
			dfs(root->right, node, n_v);
		} else {
			n_v.push_back(root);
			dfs(root->left, node, n_v);
		}

	}
	
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr)
			return nullptr;

		vector<TreeNode*> p_v;
		vector<TreeNode*> q_v;
		TreeNode *ret = nullptr;

		dfs(root, p, p_v);
		dfs(root, q, q_v);

		size_t len = p_v.size() <= q_v.size() ? p_v.size() : q_v.size();
		for (size_t i = 0; i < len; ++i) {
			if (p_v[i]->val == q_v[i]->val) {
				ret = p_v[i];
			} else {
				break;	
			} // if
		} // for

		return ret;

    }
};

int  main() {
	
	TreeNode *a1 = new TreeNode(6);
	TreeNode *a2 = new TreeNode(2);
	TreeNode *a3 = new TreeNode(8);
	TreeNode *a4 = new TreeNode(0);
	TreeNode *a5 = new TreeNode(4);
	TreeNode *a6 = new TreeNode(7);
	TreeNode *a7 = new TreeNode(9);
	TreeNode *a8 = new TreeNode(3);
	TreeNode *a9 = new TreeNode(5);

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
	TreeNode *node = obj->lowestCommonAncestor(a1, a2, a5);	
	if (node != nullptr)
		std::cout << "result:" <<  node->val << std::endl;

	return 0;	

}

