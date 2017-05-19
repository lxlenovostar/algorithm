/* * 147. Insertion Sort List
 *
 * Sort a linked list using insertion sort.
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
			
			ListNode dummy(0);
			ListNode *prev = &dummy;
			ListNode *ph = head;
			dummy.next = ph;

			while(prev->next) {
				if (ph->next->val < prev->next->val) {
					/*
				 	 * insert ph in new list.
				     * */
					std::cout << "ph->next->val:" << ph->next->val << std::endl;
					std::cout << "prev->next->val:" << prev->next->val << std::endl;

					//delete a node in list.
					ListNode *tmp1 = ph->next;
					ListNode *tmp2 = prev->next;
					ph->next = tmp1->next;

					//insert a node in list.
					prev->next = tmp1;
					tmp1->next = tmp2;

					if (!ph->next)
						break;
					
				} else {
					std::cout << "2 ph->next->val:" << ph->next->val << std::endl;
					std::cout << "2 prev->next->val:" << prev->next->val << std::endl;

					prev = prev->next;
					if (ph->next->next)
						ph = ph->next;
				}	
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
	ListNode *a = new ListNode(3);
	ListNode *b = new ListNode(1);
	b->next = a;
	ListNode *c = new ListNode(2);
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

