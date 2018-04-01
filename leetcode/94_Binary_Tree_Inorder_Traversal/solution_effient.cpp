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
			vector<int> result;

			if (root == NULL)
				return result;

			TreeNode *pos = root;
			vector<TreeNode*> tmp_stack;
			tmp_stack.push_back(pos);

			while (pos != NULL) {
				std::cout << "begin 0:" << pos->val << std::endl;

				if (pos->right != NULL) {
					std::cout << "what 2.0:" << pos->right->val << std::endl;
					tmp_stack.push_back(pos->right);
				} 
					
				if (pos->left == NULL) {
					std::cout << "what 2:" << pos->val << std::endl;
					result.push_back(pos->val); 
					tmp_stack.pop_back();
					pos = tmp_stack[tmp_stack.size() - 1]; 
					std::cout << "what 2.1:" << pos->val << std::endl;
				}
				else { 
					std::cout << "what 3\n";
					pos = pos->left;
				}
			
				/*
				// 右子树入栈
				if (pos->right != NULL) { 
					std::cout << "right tree in stack\n";
					tmp_stack.push_back(pos->right);
				}
			
				// 父节点入栈
				tmp_stack.push_back(pos);	

				if (pos->left == NULL) {
					std::cout << "what 2:" << pos->val << std::endl;
					result.push_back(pos->val); 
					tmp_stack.pop_back();
					pos = tmp_stack[tmp_stack.size()-1]; 
					std::cout << "what 2.1:" << pos->val << std::endl;
				}
				else { 
					std::cout << "what 3\n";
					pos = pos->left;
				}
				*/

			}

			return result;
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
