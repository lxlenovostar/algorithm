/* 
 * 86. Partition List
 *
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
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
		 /*
		  * similar to quick sort.
		  * */
		 ListNode* partition(ListNode* head, int x) {
			if (head == NULL || head->next == NULL) {
				return head;
			}      

			ListNode dummy_small_equal(0);
			ListNode dummy_big(0);
			ListNode *s_n = &dummy_small_equal; 
			ListNode *b_n = &dummy_big;
		    ListNode* p = head;

			while(p != NULL) {
				if (p->val < x) {
					s_n->next = p;
					assert(s_n != NULL);
					s_n = s_n->next;
				} else {
					b_n->next = p; 
					assert(b_n != NULL);
					b_n = b_n->next;
				}
				
				p = p->next;	
			}

			s_n->next = dummy_big.next;
			b_n->next = NULL;
			
			return dummy_small_equal.next;
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
	/*
	ListNode *a2 = new ListNode(2);
	ListNode *a1 = new ListNode(5);
	a1->next = a2;
	ListNode *a = new ListNode(2);
	a->next = a1;
	ListNode *b = new ListNode(3);
	b->next = a;
	ListNode *c = new ListNode(4);
	c->next = b;
	ListNode *d = new ListNode(1);
	d->next = c;
	*/

	ListNode *a2 = new ListNode(1);
	ListNode *d = new ListNode(1);
	d->next = a2;

	Solution *test = new Solution();
	test->printList(d);
	ListNode *head =  test->partition(d, 0);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	
}
