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
			if(head == NULL || head->next == NULL) {
				return head;
			} 
				
			ListNode* fast = head;
			ListNode* slow = head;
			while(fast->next != NULL && fast->next->next != NULL) {
				fast = fast->next->next;
				slow = slow->next;
						
				if(slow == fast) {
					return true;
				}
			} 
				
			return false;
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
	a->next = d;

	Solution *test = new Solution();
	std::cout << test->hasCycle(d) << std::endl;	

	return 0;	
}

