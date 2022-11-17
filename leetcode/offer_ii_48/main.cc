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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::queue<TreeNode*> m_queue;

        if (root == nullptr)
            return "";

        m_queue.push(root);
        std::string ret;
        ret += std::to_string(root->val) + ",";
        while(!m_queue.empty()) {
            auto node = m_queue.front();
            m_queue.pop();            

            if (node->left) {
                ret += std::to_string(node->left->val) + ",";
                m_queue.push(node->left); 
            }
            else{
                struct TreeNode *fake_node = new struct TreeNode(-1);
                m_queue.push(fake_node); 
                ret += "#,";
            }
            
            if (node->right) {
                ret += std::to_string(node->right->val) + ",";
                m_queue.push(node->right); 
            }
            else { 
                struct TreeNode *fake_node = new struct TreeNode(-1);
                m_queue.push(fake_node); 
                ret += "#,";
            }
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;
        std::vector<string> dataArray;
        std::vector<struct TreeNode*> data_pointer;
        string str;
        for (auto& ch : data) {
            if (ch == ',') {
                //std::cout << "str: " << str << std::endl;
                dataArray.push_back(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }
        if (!str.empty()) {
            dataArray.push_back(str);
            str.clear();
        }

        for (int i = 0; i < dataArray.size() - 1; ++i) {
            auto item = dataArray[i];
            if (item == "#") {
                data_pointer.push_back(nullptr);
                continue;
            } else {
                struct TreeNode *node = new struct TreeNode(stoi(item));
                data_pointer.push_back(node);
                int father = i >= 1 ? (i - 1)/2 : -1;
                //std::cout << "father: " << father << " i:" << i << std::endl;
                if (father >= 0 && data_pointer[father] != nullptr) {
                    if (i%2 == 0) {
                        data_pointer[father]->right = node;
                    } else {
                        data_pointer[father]->left = node;
                    }
                }
            }
        }

        return data_pointer[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{
    struct TreeNode *node1 = new struct TreeNode(1);
    struct TreeNode *node2 = new struct TreeNode(2);
    struct TreeNode *node3 = new struct TreeNode(3);
    struct TreeNode *node4 = new struct TreeNode(4);
    struct TreeNode *node5 = new struct TreeNode(5);
    struct TreeNode *node6 = new struct TreeNode(6);
    struct TreeNode *node7 = new struct TreeNode(7);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    node4->left = node6;
    node4->right = node7;
    

    Codec* test = new Codec();
    std::cout << test->serialize(node1) << std::endl;
    std::cout << test->deserialize(test->serialize(node1))->val << std::endl;

    return 0;
}
