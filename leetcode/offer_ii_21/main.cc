/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *fast = head;
        ListNode *slow = dummy;
        int count = n;

        while(count > 0 && fast != nullptr) {
            fast = fast->next;
            count--;
        }

        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *del_node = slow->next;        
        ListNode *next_next_node = del_node->next;
        slow->next = next_next_node;
        delete del_node;

        return dummy->next;
    }

    void printList(ListNode* head) {
		if(head == NULL) {
			return ;
		} 

		std::cout << head->val << std::endl;	
			while(head->next != NULL) {
				head = head->next;
				std::cout << head->val << std::endl;	
			}
	}
	
	void freeList(ListNode* head) {
		if(head == NULL) {
			return ;
		} 

		ListNode* next_head = head->next;
		delete head;

		while(next_head != NULL) {
			ListNode* tmp = next_head->next;
			delete next_head;
			next_head = tmp;	
		}
	}

};

int main() {
    ListNode *a1 = new ListNode(5);
	ListNode *a = new ListNode(4);
	a->next = a1;
	ListNode *b = new ListNode(3);
	b->next = a;
	ListNode *c = new ListNode(2);
	c->next = b;
	ListNode *d = new ListNode(1);
	d->next = c;
	//ListNode *d = new ListNode(1);

	Solution *test = new Solution();
	std::cout << "list1" << std::endl;
	test->printList(d);
	ListNode *head =  test->removeNthFromEnd(d, 2);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

    return 0;
}