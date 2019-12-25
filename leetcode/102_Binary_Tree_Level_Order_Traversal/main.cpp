/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
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
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		queue<TreeNode*> q;

		if (root == nullptr)
			return ret;

		q.push(root);

		while (! q.empty()) {
			vector<int> elem;
			queue<TreeNode*> tmp_q;
			size_t len = q.size();

			for (size_t i = 0; i < len; i++) {
				TreeNode *node = q.front();
				q.pop();
				elem.push_back(node->val);
		
				if (node->left != nullptr)
					tmp_q.push(node->left);
		
				if (node->right != nullptr)
					tmp_q.push(node->right);
			}

			q = tmp_q;
			ret.push_back(elem);
		}

		return ret;

    }
};

int  main() {
	TreeNode *a1 = new TreeNode(3);
	TreeNode *a2 = new TreeNode(9);
	TreeNode *a3 = new TreeNode(20);
	TreeNode *a4 = new TreeNode(15);
	TreeNode *a5 = new TreeNode(7);

	a1->left = a2;
	a1->right = a3;
	a3->left = a4;
	a3->right = a5;

	Solution *test = new Solution();
	vector<vector<int>> result = test->levelOrder(a1);	
	if (!result.empty()) {
		for (size_t i = 0; i < result.size(); i++) {
			for (size_t j = 0; j < result[i].size(); j++) {	
				std::cout << "result:" <<  result[i][j] << std::endl;
			}
				
			std::cout << "end" << std::endl;
		}
	}

	return 0;	

}

