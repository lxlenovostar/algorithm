#include <iostream>
#include <queue>
#include <string>
#include <vector>
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
private: 
    void dfs(TreeNode* root, int& sum) {
        if (root == nullptr)
            return;

        dfs(root->left, sum);
        sum += root->val;
        dfs(root->right, sum);
    }
    
    void update_dfs(TreeNode* root, int& sum) {
        if (root == nullptr) {
            return;
        }

        update_dfs(root->left, sum);
        int prev = root->val;
        root->val = sum;
        sum -= prev;
        //std::cout << "prev: " << prev << " sum: " << sum << std::endl;
        update_dfs(root->right, sum);
    }


public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        int sum = 0;
        dfs(root, sum);

        //std::cout << "sum: " << sum << std::endl;
        
        update_dfs(root,  sum);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{
    struct TreeNode *node1 = new struct TreeNode(4);
    struct TreeNode *node2 = new struct TreeNode(1);
    struct TreeNode *node3 = new struct TreeNode(6);
    struct TreeNode *node4 = new struct TreeNode(0);
    struct TreeNode *node5 = new struct TreeNode(2);
    struct TreeNode *node6 = new struct TreeNode(5);
    struct TreeNode *node7 = new struct TreeNode(7);
    struct TreeNode *node8 = new struct TreeNode(3);
    struct TreeNode *node9 = new struct TreeNode(8);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node5->right = node8;
    node7->right = node9;
    /*
    node3->left = node4;
    node3->right = node5;
    node4->left = node6;
    node4->right = node7;
    */
    

    Solution *test = new Solution(); 
    std::cout << test->convertBST(node1) << std::endl;

    return 0;
}
