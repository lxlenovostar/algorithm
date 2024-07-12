#include <stack>
#include <queue>
#include <iostream>

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        
        stack<TreeNode*> handle_stack;

        handle_stack.push(root);
        while(!handle_stack.empty()) {
            TreeNode* node = handle_stack.top();
            handle_stack.pop();
            TreeNode* left = node->left;
            TreeNode* right = node->right;

            if (left)
                handle_stack.push(left);
            
            if (right)
                handle_stack.push(right);

            node->right = left;
            node->left = right;
        }

        return root;
    }

    void printTree(TreeNode* root) {
        queue<TreeNode*> handle_queue;
        handle_queue.push(root);

        while(!handle_queue.empty()) {
            TreeNode* first = handle_queue.front();
            handle_queue.pop();
            std::cout << " val:" << first->val;
            TreeNode* left = first->left;
            TreeNode* right = first->right;

            if (left)
                handle_queue.push(left);
            
            if (right)
                handle_queue.push(right);

        }

        std::cout << std::endl;

    }
};

int main() {
    TreeNode *t1  = new TreeNode(4);
    TreeNode *t2  = new TreeNode(2);
    TreeNode *t3  = new TreeNode(7);
    TreeNode *t4  = new TreeNode(1);
    TreeNode *t5  = new TreeNode(3);
    TreeNode *t6  = new TreeNode(6);
    TreeNode *t7  = new TreeNode(9);

    t1->left = t2;
    t1->right = t3;

    t2->left = t4;
    t2->right = t5;

    t3->left = t6;
    t3->right = t7;

    Solution *test = new Solution();
    test->printTree(t1);
    test->printTree(test->invertTree(t1));
    return 0; 
}

