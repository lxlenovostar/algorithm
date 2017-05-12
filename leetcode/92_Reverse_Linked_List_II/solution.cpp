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
			if (!head)
				return head;

			ListNode dummy(0);
			dummy.next = head;

			ListNode *p = &dummy;
			for(int i = 1; i < m; i++) {
				p = p->next;
			}

			ListNode *pm = p->next;

			/*
             * Note: pm and p don't change.   
             */
			for (int i = m; i < n; i++) {
				ListNode *n = pm->next;
				pm->next = n->next;
				n->next = p->next;
				p->next = n;
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
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	b->next = a;
	ListNode *c = new ListNode(3);
	c->next = b;
	ListNode *d = new ListNode(4);
	d->next = c;

	Solution *test = new Solution();
	test->printList(d);
	ListNode *head =  test->reverseBetween(d, 1, 3);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	
}

