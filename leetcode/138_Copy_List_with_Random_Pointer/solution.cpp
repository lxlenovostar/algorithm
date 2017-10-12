/* 
 * 138 Copy List with Random Pointer 
 *
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 * Return a deep copy of the list.
 *
 * TODO:
 * 题目还没有看明白,什么是深度拷贝
 * */

#include <iostream>
#include <assert.h>

/*
 * Definition for singly-linked list with a random pointer.
 */ 
struct RandomListNode {
	int label;
 	RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


class Solution {
	public:
		RandomListNode *copyRandomList(RandomListNode *head) {
			if (head == NULL) {
				return NULL;
			}

			RandomListNode dummy(0);
			RandomListNode *n = &dummy;
			RandomListNode *h = head;
			map<RandomListNode*, RandomListNode*> m;

			while(h) {
				RandomListNode *node = new RandomListNode(h->label);
				n->next = node;
				n = node;

				node->random = h->random;
				// TODO 这一行用来做什么
				m[h] = node;

				h = h->next;
			}

			h = dummy.next;
			while(h) {
				if (h->random != NULL) {
					h->random = m[h->random];
				}
				h = h->next;
			}

			return dummy.next;
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
	ListNode *a2 = new ListNode(3);
	ListNode *a1 = new ListNode(4);
	a1->next = a2;
	ListNode *a = new ListNode(2);
	a->next = a1;

	ListNode *b = new ListNode(7);
	ListNode *c = new ListNode(6);
	c->next = b;
	ListNode *d = new ListNode(5);
	d->next = c;

	Solution *test = new Solution();
	test->printList(a);
	test->printList(d);
	ListNode *head = test->addTwoNumbers(d, a);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	
}
