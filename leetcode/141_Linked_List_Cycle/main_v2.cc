#include <iostream>
#include <vector>
#include <queue>
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
	bool hasCycle(ListNode* head) {
		if (head == nullptr)
			return false;
		
		struct ListNode* first = head;
		struct ListNode* second = head;

		while (first && first->next) {
			first = first->next->next;
			second = second->next;

			if (first == second)
				return true;
		}

		return false;
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
	std::cout << "list1" << std::endl;
	test->printList(d);
	std::cout << "ret: " << test->hasCycle(d) << std::endl;	

	return 0;	
}

