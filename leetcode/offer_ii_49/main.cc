#include <iostream>
#include <queue>
#include <string>
#include <vector>

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
  void dfs1(TreeNode* root, int add, int& sum) {
        if (root == nullptr) {
            return;
        } 

        add = add*10 + root->val;
        
        std::cout << "val: " << root->val << " sum: " << sum  << " add: " << add << std::endl; 

        if (root->left == nullptr && root->right == nullptr) {
            sum += add;
            return;
        }
        
        dfs1(root->left, add, sum); 
        dfs1(root->right, add, sum);

        return ;
    }


    int dfs(TreeNode* root, int add) {
        if (root == nullptr) {
            return 0;
        } 

        add = add*10 + root->val;
        
        std::cout << "val: " << root->val << " add: " << add << std::endl; 
        
        if (root->left == nullptr && root->right == nullptr) {
            return add;
        }

        return  dfs(root->left, add) + dfs(root->right, add);
    }

public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if (root == nullptr)
            return sum;
        return dfs(root, 0); 

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{
    struct TreeNode *node1 = new struct TreeNode(4);
    struct TreeNode *node2 = new struct TreeNode(9);
    struct TreeNode *node3 = new struct TreeNode(0);
    struct TreeNode *node4 = new struct TreeNode(5);
    struct TreeNode *node5 = new struct TreeNode(1);
    /*
    struct TreeNode *node6 = new struct TreeNode(6);
    struct TreeNode *node7 = new struct TreeNode(7);
    */
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    /*
    node3->left = node4;
    node3->right = node5;
    node4->left = node6;
    node4->right = node7;
    */
    

    Solution *test = new Solution(); 
    std::cout << test->sumNumbers(node1) << std::endl;

    return 0;
}
