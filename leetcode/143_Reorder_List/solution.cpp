/* 
 * 143. Reorder List
 * 
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * You must do this in-place without altering the nodes' values.
 * 
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}. 
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
		ListNode* reorderList(ListNode* head) {
			if (head == NULL || head->next == NULL) {
				return head;
			}      

			ListNode *fast = head;
			ListNode *slow = head;

			/*
			 * get two lists.
			 * */
			while (fast->next != NULL && fast->next->next != NULL) {
				fast = fast->next->next;
				slow = slow->next;
			}
			fast = slow->next;
			slow->next = NULL;

			/*
			 * rotate a list.
			 * dummy is used to build a new list.
			 * */
			ListNode dummy(0);
			while (fast) {
				ListNode *n = dummy.next;
				dummy.next = fast;
				ListNode *nn = fast->next;
				fast->next = n;
				fast = nn;
			}

			slow = head;
			fast = dummy.next;

			/*
			 * two list join into one list. 
			 * */
			while(slow) {
				if (fast != NULL) {
					ListNode *n = slow->next;
					slow->next = fast;
					ListNode *nn = fast->next;
					fast->next = n;
					fast = nn;
					slow = n;
				} else {
					break;
				}
			}

			return head;
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
	//ListNode *a1 = new ListNode(5);
	ListNode *a = new ListNode(4);
	//a->next = a1;
	ListNode *b = new ListNode(3);
	b->next = a;
	ListNode *c = new ListNode(2);
	c->next = b;
	ListNode *d = new ListNode(1);
	d->next = c;

	Solution *test = new Solution();
	test->printList(d);
	ListNode *head =  test->reorderList(d);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	
}

