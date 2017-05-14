/*
 * 148. Sort List
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
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
		ListNode* sortList(ListNode* head) {
			if (!head || !head->next)
				return head;
			
			ListNode* fast = head;
			ListNode* slow = head;

			/*
			 * a good way: find the half list.
			 * */
			while(fast->next && fast->next->next) {
				fast = fast->next->next;
				slow = slow->next;
			}

			fast = slow->next;
			slow->next = NULL;

			ListNode* p1 = sortList(head);
			ListNode* p2 = sortList(fast);

			return merge(p1, p2);
		}

		ListNode* merge(ListNode* l1, ListNode* l2) {
			ListNode dummy(0);
			ListNode* p = &dummy;
										
			while(l1 && l2) {
				int val1 = l1->val;
				int val2 = l2->val;
																							
				if(val1 < val2) {
					p->next = l1;
					p = l1;
					l1 = l1->next;
				} else {
					p->next = l2;
					p = l2;
					l2 = l2->next;
				}
			}

			if (l1 && !l2)
				p->next = l1;
			else if (l2 && !l1)
				p->next = l2;

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
	ListNode *head =  test->sortList(d);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	
}

