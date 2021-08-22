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

#include <iostream>

class Solution {
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {							    
			while (root != nullptr) {
				if (root->val > p->val && root->val > q->val)
						root = root->left;
				else if (root->val < p->val && root->val < q->val)
						root = root->right;
				else 
						return root;
			}
						
			return nullptr;
		}

		/*
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {							    
			if (root->val > p->val && root->val > q->val)
					return lowestCommonAncestor(root->left, p, q);
			if (root->val < p->val && root->val < q->val)
					return lowestCommonAncestor(root->right, p, q);
						
			return root;
		}
		*/
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

