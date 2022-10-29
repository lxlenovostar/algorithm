#include <iostream>
#include <vector>
/*
 * Definition for singly-linked list.
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
	public:
		ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
			ListNode dummy(0);
			ListNode* tail = &dummy;

			while (l1 && l2) {
				if (l1->val < l2->val) {
					tail->next = l1;
					l1 = l1->next;
				} else {
					tail->next = l2;
					l2 = l2->next;
				}
				tail = tail->next;
			}

			tail->next = l1 != nullptr ? l1 : l2;

			return dummy.next;
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

int  main() {
	ListNode *a = new ListNode(3);
	ListNode *b = new ListNode(2);
	b->next = a;
	ListNode *c = new ListNode(4);
	ListNode *d = new ListNode(1);
	d->next = c;

	Solution *test = new Solution();
	std::cout << "list1" << std::endl;
	test->printList(b);
	std::cout << "list2" << std::endl;
	test->printList(d);
	ListNode *head =  test->mergeTwoLists(b, d);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	
}

