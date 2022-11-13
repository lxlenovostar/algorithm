#include <queue>
#include <iostream>
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

class CBTInserter {
private:
    std::vector<struct TreeNode*> m_queue;
public:
    CBTInserter(TreeNode* root) {
        if (root == nullptr)
            return;
        
        m_queue.push_back(root);
        std::queue<struct TreeNode*> tmp_queue;
        tmp_queue.push(root);

        while(!tmp_queue.empty()) {
            auto node = tmp_queue.front();
            tmp_queue.pop();

            if (node->left != nullptr) {
                tmp_queue.push(node->left);
                m_queue.push_back(node->left);
            }
            
            if (node->right != nullptr) {
                tmp_queue.push(node->right);
                m_queue.push_back(node->right);
            }
        }

    }
    
    int insert(int v) {
        auto tail = m_queue.back();
    
        struct TreeNode *node = new struct TreeNode(v);
        
        int index = m_queue.size();
        int father = (index-1) / 2;
        //std::cout << "index: " << index << " father: " << father << std::endl; 
        if (index%2 == 0)
            m_queue[father]->right = node;
        else {
            m_queue[father]->left = node;
        }
        m_queue.push_back(node);
        return m_queue[father]->val;
        
    }
    
    TreeNode* get_root() {
        return m_queue.front();
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 */
int main() {
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
    CBTInserter* obj = new CBTInserter(node1);
    int param = obj->insert(7);
    std::cout << param << std::endl;
    param = obj->insert(8);
    std::cout << param << std::endl;
    TreeNode* param_2 = obj->get_root();

    return 0;
}