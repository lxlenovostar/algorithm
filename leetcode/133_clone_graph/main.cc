#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        
        Node* clone_node;
        if (check_node.find(node->val) == check_node.end()) {
            clone_node = new Node(node->val);
            check_node.insert({clone_node->val, clone_node});
        } else {
            return nullptr;
        }

        for (auto neg = node->neighbors.begin() ; neg != node->neighbors.end(); neg++) {
            Node* clone_neg;
            if (check_node.find((*neg)->val) == check_node.end()) {
                clone_neg = cloneGraph(*neg);
            } else {
                clone_neg = check_node.find((*neg)->val)->second;
            }
            
            if (clone_neg != nullptr)
                clone_node->neighbors.push_back(clone_neg);
        }

        return clone_node;
    }
private:
    map<int, Node*> check_node;
};

int main() {
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    Solution *test = new Solution();
    Node *ret = test->cloneGraph(node1);

    return 0;
}