#include <vector>
#include <iostream>
#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    int kthSmallest(TreeNode* root, int k) {
        stack<int> check_val;

        helper(root, check_val);        

        while (check_val.size() > k) {
            //auto val = check_val.top();
            //std::cout << "what: " << val << std::endl;
            check_val.pop();
        }

        return check_val.top();
    }
private:
    void helper(TreeNode *node, stack<int>& node_vals) {
        if (node == nullptr)
            return;
        
        helper(node->left, node_vals);
        node_vals.push(node->val);
        helper(node->right, node_vals);
    }
};

int main() {
    struct TreeNode *a1 = new TreeNode(3);
    struct TreeNode *a2 = new TreeNode(1);
    struct TreeNode *a3 = new TreeNode(4);
    struct TreeNode *a4 = new TreeNode(2);
    
    a1->left = a2;
    a1->right = a3;
    a2->right = a4;

    int k = 1;

    Solution *test = new Solution();
    std::cout << test->kthSmallest(a1, k) << std::endl;

    return 0;
}