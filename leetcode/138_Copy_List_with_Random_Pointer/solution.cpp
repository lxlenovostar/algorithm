/* 
 * 138 Copy List with Random Pointer 
 *
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 * Return a deep copy of the list.
 *
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

			RandomListNode *h = head;
			RandomListNode *node;
			RandomListNode *temp;
			RandomListNode dummy(0);

			while(h) {
				node = new RandomListNode(h->label);
				node->random = h->random;
				temp = h->next;
				h->next = node;
				node->next = temp;
				h = temp;
			}

			std::cout << "step 0" << std::endl;
			h = head;
			while(h != NULL) {
				std::cout << h->label << std::endl;	
				h = h->next;
			}

			std::cout << "step 1" << std::endl;
			h = head->next;
			while(h) {
				if (h->random != NULL) {
					h->random = h->random->next;				
				}
				if (h->next)
					h = h->next->next;
				else 
					break;
			}

			std::cout << "step 2" << std::endl;
			h = head;
			node = &dummy;
			while(h) {
				node->next = h->next;
				temp = h->next->next;
				h->next = temp;
				h = h->next;
				node = node->next;
			}
			
			std::cout << "step 3" << std::endl;

			return dummy.next;
		}

		void printList(RandomListNode* head) {
			if(head == NULL) {
				return ;
			} 

			std::cout << head->label << std::endl;	
			while(head->next != NULL) {
				head = head->next;
				std::cout << head->label << std::endl;	
			}
		}
	
		void freeList(RandomListNode* head) {
			if(head == NULL) {
				return ;
			} 

			RandomListNode* tmp = head->next;
			while(head != NULL) {
				tmp = head->next;
				delete head;
				head = tmp;	
			}
		}

};

int  main() {
	/*RandomListNode *a3 = new RandomListNode(4);
	RandomListNode *a2 = new RandomListNode(3);
	a2->next = a3;
	*/
	RandomListNode *a1 = new RandomListNode(-1);
	//a1->next = a2;
	RandomListNode *a = new RandomListNode(-1);
	a->next = a1;
	//a->random = a3;

	Solution *test = new Solution();
	test->printList(a);
	RandomListNode *head = test->copyRandomList(a);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	
}
