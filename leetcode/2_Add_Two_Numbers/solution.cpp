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
			if (l1 == NULL && l2 == NULL) {
				return NULL;
			}
			else if (l1 == NULL && l2) {
				return l2;
			} else if (l2 == NULL && l1) {
				return l1;
			}
				
			ListNode *p1 = l1;
			ListNode *p2 = l2;
			int mid_value = 0;
			int carry = 0;
			size_t p1_len = 0;
			size_t p2_len = 0;

			while(p1) {
				p1_len++;
				p1 = p1->next;
			}
			p1 = l1;

			while(p2) {
				p2_len++;
				p2 = p2->next;
			}
			p2 = l2;

			size_t min = p2_len < p1_len ? p2_len : p1_len;
			while(min) {
				std::cout << "sum:" << (p1->val + p2->val) << std::endl;	
			    mid_value = p1->val + p2->val + carry;	
				if (mid_value >= 10) {
					p1->val = mid_value%10;	
					p2->val = mid_value%10;	
					carry = 1;
				} else {
					p1->val = mid_value;
					p2->val = mid_value;
					carry = 0;
				}

				p1 = p1->next;
				p2 = p2->next;

				min--;
			}

			/* too complicated too complicated.
			while (p1) {
				if (carry) {
					mid_value = p1->val + 1;				
					if (mid_value >= 10) {
						p1->val = mid_value%10;	
						carry = 1;
						continue;
					} else {
						p1->val = mid_value;
						carry = 0;
					}
				} 
				
				return l1;
			}

			while (p2) {
				if (carry) {
					mid_value = p2->val + 1;				
					if (mid_value >= 10) {
						p2->val = mid_value%10;	
						carry = 1;
						continue;
					} else {
						p2->val = mid_value;
						carry = 0;
					}
				} 
				
				return l2;
			}
			*/

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
	//ListNode *a2 = new ListNode(4);
	ListNode *a1 = new ListNode(9);
	//a1->next = a2;
	ListNode *a = new ListNode(9);
	a->next = a1;

	/*
	ListNode *b = new ListNode(6);
	ListNode *c = new ListNode(4);
	c->next = b;
	*/
	ListNode *d = new ListNode(1);
	//d->next = c;


	Solution *test = new Solution();
	test->printList(a);
	ListNode *head =  test->addTwoNumbers(d, a);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	
}
