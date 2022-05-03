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
			if(head == nullptr) {
				return nullptr;
			} 

			ListNode *slow;
			ListNode *fast;
			slow = fast = head;

			while (fast != nullptr) {
				if 	(slow->val != fast->val) {
					slow->next = fast;
					slow = slow->next;	
				}
				fast = fast->next;	
			}
			slow->next = nullptr;

			return head;
		}
		
		void freeList(ListNode* head) {
			while(head != NULL) {
				ListNode* tmp = head->next;
				delete head;
				head = tmp;	
			}
		}
			
		void printList(ListNode* head) {
			while(head != NULL) {
				std::cout << head->val << std::endl;	
				head = head->next;
			}
		}


};

int  main() {
	ListNode *a1 = new ListNode(3);
	ListNode *a = new ListNode(3);
	a->next = a1;
	ListNode *b = new ListNode(2);
	b->next = a;
	ListNode *c = new ListNode(1);
	c->next = b;
	ListNode *d = new ListNode(1);
	d->next = c;

	Solution *test = new Solution();
	ListNode *head =  test->deleteDuplicates(d);	
	test->printList(head);
	test->freeList(head);

	return 0;	
}

