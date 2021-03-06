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
			ListNode *end_point_p1;
			ListNode *end_point_p2;
			int tmp_value = 0;
			int carry = 0;
			size_t p1_len = 0;
			size_t p2_len = 0;

			// get len.
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
			    tmp_value = p1->val + p2->val + carry;	
				if (tmp_value >= 10) {
					p1->val = tmp_value%10;	
					p2->val = tmp_value%10;	
					carry = 1;
					std::cout << "1 value:" << p1->val << std::endl;	
				} else {
					p1->val = tmp_value;
					p2->val = tmp_value;
					carry = 0;
					std::cout << "2 value:" << p1->val << std::endl;	
				}

				end_point_p1 = p1;
				end_point_p2 = p2;
				p1 = p1->next;
				p2 = p2->next;
				min--;
			}

			if (p1_len >= p2_len) {
				while(p1) {
					if (carry) {
						tmp_value = p1->val + carry;
						if (tmp_value >= 10) {
							p1->val = tmp_value%10;
							carry = 1;
							std::cout << "3 value:" << p1->val << std::endl;	
						} else {
							p1->val = tmp_value;
							carry = 0;
							std::cout << "4 value:" << p1->val << std::endl;	
						}
					} 

					end_point_p1 = p1;
					p1 = p1->next;
				}

				if (carry) {
					ListNode *new_node = new ListNode(1);
					end_point_p1->next = new_node;
				}

				return l1; 
			} else {
				while(p2) {
					if (carry) {
						tmp_value = p2->val + carry;
						if (tmp_value >= 10) {
							p2->val = tmp_value%10;
							carry = 1;
							std::cout << "5 value:" << p2->val << std::endl;	
						} else {
							p2->val = tmp_value;
							carry = 0;
							std::cout << "6 value:" << p2->val << std::endl;	
						}
					} 

					end_point_p2 = p2;
					p2 = p2->next;
				}

				if (carry) {
					ListNode *new_node = new ListNode(1);
					end_point_p2->next = new_node;
				}


				return l2; 
			}

			return NULL;
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
