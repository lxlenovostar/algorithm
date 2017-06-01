/* 
 * 61. Rotate List
 *
 * Given a list, rotate the list to the right by k places, 
 * where k is non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
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
		ListNode* rotateRight(ListNode* head, int k) {
			if (k <= 0 || !head)
				return head;

			int list_len = 1;
			int cut_pos = -1;
			ListNode *result = head;

			while(result->next) {
				result = result->next;
				list_len++;
			}

			std::cout << "list_len:" << list_len << std::endl;

			//build a cycle.
			result->next = head;

			cut_pos = list_len - k%list_len;

			for (int i = 0; i < cut_pos; i++) {
				result = result->next;
			}

			head = result->next;
			result->next = NULL;

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
	ListNode *a1 = new ListNode(5);
	ListNode *a = new ListNode(4);
	a->next = a1;
	ListNode *b = new ListNode(3);
	b->next = a;
	ListNode *c = new ListNode(2);
	c->next = b;
	ListNode *d = new ListNode(1);
	d->next = c;

	Solution *test = new Solution();
	test->printList(d);
	ListNode *head =  test->rotateRight(d, 2);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	
}

