/*
 * 21. Merge Two Sorted Lists
 *
 * Merge two sorted linked lists and return it as a new list. The new list should be made by 
 * splicing together the nodes of the first two lists.
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
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			if (l1 && !l2)
				return l1;
			else if (l2 && !l1)
				return l2;
			else if (!l1 && !l2)
				return NULL;
			else {
				ListNode newhead(0);		
				ListNode current = NULL;

				while(l1 != NULL && l2 != NULL) {
					if (l1.val <= l2.val) {
						if (!newhead.next)
							newhead.next = l1;

						current = l1;
						l1 = l1->next;
					}
					else { 	
						if (!newhead.next)
							newhead.next = l2;

						current = l2;
						l2 = l2->next;
					}

					current = current->next;
				}


				return newhead.next;
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
	ListNode *a = new ListNode(2);
	ListNode *b = new ListNode(2);
	b->next = a;
	/*
	ListNode *c = new ListNode(1);
	c->next = b;
	ListNode *d = new ListNode(1);
	d->next = c;
	*/

	Solution *test = new Solution();
	test->printList(b);
	ListNode *head =  test->deleteDuplicates(b);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	
}

