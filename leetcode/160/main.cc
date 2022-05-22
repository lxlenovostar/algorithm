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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr)
			return nullptr;
		
		struct ListNode* head = headA;
		int headA_size = 0;
		while(head) {
			headA_size++;
			head = head->next;
		}
		
		head = headB;
		int headB_size = 0;
		while(head) {
			headB_size++;
			head = head->next;
		}

		struct ListNode* head_a = headA;
		struct ListNode* head_b = headB;

		if (headA_size > headB_size) {
			while (headA_size-- > headB_size) {
				head_a = head_a->next;
			}
		} else if (headB_size > headA_size) {
			while (headB_size-- > headA_size) {
				head_b = head_b->next;
			}
		}

		while(head_a && head_b) {
			if (head_a == head_b)
				return head_a;

			head_a = head_a->next;
			head_b = head_b->next;
		}

		return nullptr;
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
	ListNode *e = new ListNode(0);
	e->next = c;
	ListNode *f = new ListNode(-1);
	f->next = e;

	Solution *test = new Solution();
	std::cout << "list1" << std::endl;
	test->printList(d);
	std::cout << "list2" << std::endl;
	test->printList(f);
	ListNode *ret = test->getIntersectionNode(d, f);	
	std::cout << "ret" << std::endl;
	test->printList(ret);

	return 0;	
}

