#include <iostream>
using namespace std;

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
 
 // 可以多分配点内存，这样实现简单些。
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode dummy(0);

        struct ListNode *ptr = &dummy;
        int cn = 0;
        while (l1 || l2) {
            int value = cn + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            cn =  value / 10;
            value = value % 10;

            ptr->next = new ListNode(value);
            ptr = ptr->next;

            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }

        if (cn) {
            ptr->next = new ListNode(cn);
            //ptr = ptr->next;
        }

        return dummy.next;
    }
};

int main() {
    struct ListNode *a1 = new ListNode(2);
    struct ListNode *a2 = new ListNode(4);
    struct ListNode *a3 = new ListNode(3);

    a1->next = a2;
    a2->next = a3;
 
    struct ListNode *b1 = new ListNode(5);
    struct ListNode *b2 = new ListNode(6);
    struct ListNode *b3 = new ListNode(4);

    b1->next = b2;
    b2->next = b3;

    Solution *test = new Solution();
    struct ListNode *ret = test->addTwoNumbers(a1, b1);

    for (struct ListNode *tmp = ret; tmp != nullptr; tmp = tmp->next) {
        std::cout << tmp->val << std::endl;
    }

    return 0;

}