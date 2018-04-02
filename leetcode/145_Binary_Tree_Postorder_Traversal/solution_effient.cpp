/* 
 * 94. Binary Tree Inorder Traversal 
 *
 * Given a binary tree, return the inorder traversal of its nodes' values. 
 *
 * */

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

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
		vector<int> inorderTraversal(TreeNode* root) {
			vector<int> vals;
		
			if (root == NULL) {
				return vals;
			}

			vector<TreeNode*> nodes;
			TreeNode* p = root;

			while (p || !nodes.empty()) {
				// 这里一直遍历左子树，将根节点压栈
				while(p) {
					nodes.push_back(p);
					p = p->left;
				}

				if (!nodes.empty()) {
					p = nodes.back();
					vals.push_back(p->val);

					// 将根节点弹出，获取右子树
					nodes.pop_back();
					p = p->right;
				}
			
			}

			return vals;
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
	TreeNode *a3 = new TreeNode(3);

	a1->right = a2;
	a2->left = a3;

	Solution *test = new Solution();
	vector<int> result = test->inorderTraversal(a1);	
	vector<int>::iterator iter;
	for (iter = result.begin(); iter != result.end(); iter++ )
		std::cout << "result:" <<  *iter << std::endl;

	return 0;	
}
