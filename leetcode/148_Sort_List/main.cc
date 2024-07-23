#include <iostream>
#include <queue>

/**
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

struct PriorityNode {
    int key;
    struct ListNode* node;
    PriorityNode(int x, ListNode* ptr): key(x), node(ptr) {}
    friend bool operator<(const PriorityNode & lhs, const PriorityNode & rhs) {
        return lhs.key > rhs.key;
    }
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr)
            return head;
        
        std::priority_queue<PriorityNode> handle;
        struct ListNode dummy(0);

        for (struct ListNode *tmp = head; tmp != nullptr; tmp = tmp->next) {
            struct PriorityNode h = {tmp->val, tmp};
            handle.push(h);
        }

        struct ListNode *tmp = &dummy;
        while(!handle.empty()) {
            auto h = handle.top();
            handle.pop();
            tmp->next = h.node;
            tmp = h.node;
            tmp->next = nullptr;
        }

        return dummy.next; 
    }
};

int main() {
    struct ListNode *a1 = new ListNode(4);
    struct ListNode *a2 = new ListNode(2);
    struct ListNode *a3 = new ListNode(1);
    struct ListNode *a4 = new ListNode(3);

    a1->next = a2;
    a2->next = a3;
    a3->next = a4;

    Solution *test = new Solution();
    test->sortList(a1);
    
    return 0;
}
