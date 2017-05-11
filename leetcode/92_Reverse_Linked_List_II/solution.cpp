/*
 * 92. Reverse Linked List II 
 * 
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * return 1->4->3->2->5->NULL.
 
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 * */

#include <iostream>
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
		struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
			int start = m;
			ListNode dummy(0);
			ListNode* prev = &dummy;
			prev->next = head;

			if (m < n)
				return head;

			while(m > 1) {
				prev = prev->next;
				m--;
			} 

			ListNode* p1 = prev;
			ListNode* p2 = p1->next;
			ListNode* p3 = p2->next;

			while(start < n) {
				start++;
				
				p2->next = p3->next;
				p1->next = p3;
				p3->next = p2;
			}
			
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
	ListNode *head =  test->mergeTwoLists(NULL, NULL);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	
}

