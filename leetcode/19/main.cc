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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr || head->next == nullptr)
			return nullptr;
		
		struct ListNode* first = head;
		struct ListNode dump(-1);
		dump.next = head;
		struct ListNode* second = &dump;
		int step = n;
		while(step>0) {
			first = first->next;
			step--;
		}

		while(first != nullptr) {
			first = first->next;			
			second = second->next;			
		}
		struct ListNode*  n_node = second->next;
		
		second->next = n_node->next;

		return dump.next;
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
	/*ListNode *a1 = new ListNode(5);
	ListNode *a = new ListNode(4);
	a->next = a1;
	ListNode *b = new ListNode(3);
	b->next = a;
	*/
	ListNode *c = new ListNode(2);
	//c->next = b;
	ListNode *d = new ListNode(1);
	d->next = c;

	Solution *test = new Solution();
	std::cout << "list1" << std::endl;
	test->printList(d);
	ListNode *head =  test->removeNthFromEnd(d, 2);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	
}

