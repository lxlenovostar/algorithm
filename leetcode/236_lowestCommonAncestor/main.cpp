/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]


示例 1:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
示例 2:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 

说明:

所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉树中。
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
#include <vector>
#include <stack>
#include <limits>

using namespace std;

class Solution {
public:
	
	//recu
    TreeNode* lowestCommonAncestor_1(TreeNode* root, TreeNode* p, TreeNode* q) {
	
		if (root == nullptr)	
			return nullptr;

		if (root->val == p->val || root->val == q->val)
			return root;

		/*
		在左、右子树中分别查找是否包含p或q：
			如果以下两种情况（左子树包含p，右子树包含q/左子树包含q，右子树包含p），那么此时的根节点就是最近公共祖先
			如果左子树包含p和q，那么到root->left中继续查找，最近公共祖先在左子树里面
			如果右子树包含p和q，那么到root->right中继续查找，最近公共祖先在右子树里面
		*/

		TreeNode *left =  lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);

		if (left != nullptr && right != nullptr) {
			return root;
		} else if (left != nullptr) {
			return left;
		} else if (right != nullptr) {
			return right;
		}

		return nullptr;
    }
	
	bool dfs(TreeNode *root, TreeNode *node, vector<TreeNode*> &n_v) {
		if (root == nullptr) {	
			return false;
		}

		if (root->val == node->val) {
			n_v.push_back(root);
			return true;
		}

		n_v.push_back(root);
		bool left = dfs(root->left, node, n_v);
		if (left == true)
			return true;

		bool right = dfs(root->right, node, n_v);
		if (right == true)
			return true;

		n_v.erase(n_v.end() - 1);

		return false;
		
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

