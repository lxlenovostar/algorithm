/*
 * 82. Remove Duplicates from Sorted List II
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
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

		ListNode* deleteDuplicates(ListNode* head) {
			ListNode *result = head;
			if(head == NULL || head->next == NULL) {
				return result;
			} 
				
			int head_value = head->val; 

			while(head != NULL && head->next != NULL) {
				ListNode* tmp = head->next;

				if (head->val == tmp->val) {
					if (tmp->val == head_value)
						result = tmp;
					
					delete head;
				} else {
					if (head->val == head_value)
						head_value = tmp->val;
				} 
					
				head = tmp;
			}
				
			return result;
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
	ListNode *a = new ListNode(4);
	ListNode *b = new ListNode(4);
	b->next = a;
	ListNode *c = new ListNode(2);
	c->next = b;
	ListNode *d = new ListNode(1);
	d->next = c;

	Solution *test = new Solution();
	test->printList(d);
	ListNode *head =  test->deleteDuplicates(d);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	
}

