#include <iostream>
#include <queue>
#include <string>
#include <list>

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
        if (root == nullptr)
            return "#";
        
        string left_str = serialize(root->left);
        string right_str = serialize(root->right);

        return std::to_string(root->val) + "," + left_str + "," + right_str;
    }
    
    TreeNode* dfs(std::list<string> &dataArray) {
        if (dataArray.front() == "#") {
            dataArray.erase(dataArray.begin());
            return nullptr;
        }
        
        struct TreeNode *node = new struct TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        node->left = dfs(dataArray);
        node->right = dfs(dataArray);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;
        std::list<string> dataArray;
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

        return dfs(dataArray);
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
