/* 
 * 2 Add Two Numbers
 *
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * */

#include <iostream>
#include <assert.h>

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
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode dummy(0);
			ListNode *p = &dummy;

			int cn = 0;
			while(l1 || l2) {
				int val = cn + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
				cn = val / 10;
				val = val %10;
				p->next = new ListNode(val);
				p = p->next;
				if (l1) {
					l1 = l1->next;
				}
				if (l2) {
					l2 = l2->next;
				}
			}

			if (cn != 0) {
				p->next = new ListNode(cn);
				p = p->next;
			}

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
	ListNode *a2 = new ListNode(3);
	ListNode *a1 = new ListNode(4);
	a1->next = a2;
	ListNode *a = new ListNode(2);
	a->next = a1;

	ListNode *b = new ListNode(7);
	ListNode *c = new ListNode(6);
	c->next = b;
	ListNode *d = new ListNode(5);
	d->next = c;

	Solution *test = new Solution();
	test->printList(a);
	test->printList(d);
	ListNode *head = test->addTwoNumbers(d, a);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	
}
