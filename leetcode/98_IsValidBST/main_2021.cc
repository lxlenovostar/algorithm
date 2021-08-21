/**
 * Definition for a binary tree node.
 */
#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
		if (root == nullptr)
			return true;

		return helper(root, LONG_MIN, LONG_MAX);
    }

private:
	bool helper(TreeNode* node, long min, long max) {
		if (node == nullptr) { 
			//std::cout << "what0" << std::endl;		
			return true;
		}

		if (node->val <= min || node->val >= max) { 
			//std::cout << "what1 node->val: " <<  node->val << " min: " << min << " max: " << max << std::endl;		
			return false;
		}

		return (helper(node->left, min, node->val) && helper(node->right, node->val, max));
	}

};

int main() {
	TreeNode *a1 = new TreeNode(10);
	TreeNode *a2 = new TreeNode(5);
	TreeNode *a3 = new TreeNode(15);
	TreeNode *a4 = new TreeNode(6);
	TreeNode *a5 = new TreeNode(20);

	a1->left = a2;
	a1->right = a3;
	a3->left = a4;
	a3->right = a5;
	

	/*
	struct TreeNode *a1 = new TreeNode(2);	
	struct TreeNode *a2 = new TreeNode(1);
	struct TreeNode *a3 = new TreeNode(3);

	a1->left = a2;
	a1->right = a3;
	*/

	Solution *test = new Solution();
	std::cout << test->isValidBST(a1) << std::endl;

	return 0;
}
