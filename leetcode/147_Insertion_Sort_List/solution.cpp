/*
 * 147. Insertion Sort List
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
			ListNode *ph = head;
			ListNode *pd = &dummy;

			pd->next = ph;
			pd = pd->next;
			ph = ph->next;

			while(ph) {
				ListNode *tmp = pd;
				while(tmp->next) {
					if (ph->val <= tmp->val) {
						/*
					 	 * insert ph in new list.
					     * */
						tmp1 = ph;
						ph = ph->next;
						tmp1->next = tmp->next;
						tmp->next = tmp1;
					} else {
						tmp = tmp->next;	
				    }	
				}

				if (!tmp) 
					//insert ph in tail.

				pd = pd->next;
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
	ListNode *head =  test->sortList(d);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	
}

