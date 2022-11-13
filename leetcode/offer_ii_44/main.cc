#include <iostream>
#include <queue>
#include <limits>

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr)
            return ret;
        
        std::queue<TreeNode*> m_queue; 
        m_queue.push(root);

        while (!m_queue.empty()) {
            std::queue<TreeNode*> tmp_queue; 
            int max_val = std::numeric_limits<int>::min();

            while (!m_queue.empty()) {
                auto item = m_queue.front();
                m_queue.pop();

                if (item->left)
                    tmp_queue.push(item->left);
                
                if (item->right)
                    tmp_queue.push(item->right);

                max_val = std::max(max_val, item->val);
                std::cout << "max_val " << max_val << std::endl;
            }

            std::swap(m_queue, tmp_queue);
            ret.push_back(max_val);
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
    for (const auto& item : test->largestValues(node1)) {
        std::cout << item << std::endl;
    }

    return 0;
}
