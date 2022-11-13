#include <iostream>
#include <queue>

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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ret;
        if (root == nullptr)
            return ret;
        
        std::queue<TreeNode*> m_queue; 
        m_queue.push(root);
        ret.push_back(root->val);

        while (!m_queue.empty()) {
            std::queue<TreeNode*> tmp_queue; 

            while (!m_queue.empty()) {
                auto item = m_queue.front();
                std::cout << "item: " << item << std::endl;
                m_queue.pop();

                if (item->left)
                    tmp_queue.push(item->left);
                
                if (item->right)
                    tmp_queue.push(item->right);
            }

            if (!tmp_queue.empty()) {
                ret.push_back(tmp_queue.back()->val);
                std::swap(m_queue, tmp_queue);
            }
        }

        return ret;
    }
};

int main()
{
    struct TreeNode *node1 = new struct TreeNode(1);
    struct TreeNode *node2 = new struct TreeNode(2);
    struct TreeNode *node3 = new struct TreeNode(3);
    struct TreeNode *node4 = new struct TreeNode(4);
    struct TreeNode *node5 = new struct TreeNode(5);
    struct TreeNode *node6 = new struct TreeNode(6);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;

    Solution* test = new Solution();
    for (const auto& item : test->rightSideView(node1)) {
        std::cout << item << std::endl;
    }

    return 0;
}
