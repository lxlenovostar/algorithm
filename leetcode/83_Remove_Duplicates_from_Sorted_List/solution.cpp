/*
 * 83. Remove Duplicates from Sorted List
 *
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 *
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
		ListNode* deleteDuplicates(ListNode* head) {
			ListNode *result = head;
			if(head == NULL || head->next == NULL) {
				return result;
			} 
				
			while(head->next != NULL) {
				ListNode* tmp = head->next;

				if (head->val == tmp->val) {
					head->next = tmp->next;	
					delete tmp;
				} else {
					head = head->next;	
				}
			} 
				
			return result;
		}
		
		void freeList(ListNode* head) {
			if(head == NULL) {
				return ;
			} 

			ListNode* next_head = head->next;
			delete head;

			while(next_head->next != NULL) {
				ListNode* tmp = next_head->next;
				delete next_head;
				next_head = tmp;	
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


};

int  main() {
	ListNode *a = new ListNode(2);
	ListNode *b = new ListNode(2);
	b->next = a;
	ListNode *c = new ListNode(3);
	c->next = b;
	ListNode *d = new ListNode(4);
	d->next = c;

	Solution *test = new Solution();
	ListNode *head =  test->deleteDuplicates(d);	
	test->printList(head);
	test->freeList(head);

	return 0;	
}

