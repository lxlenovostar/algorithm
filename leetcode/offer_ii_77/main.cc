
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
		ListNode* split(ListNode* head) {
			if (!head)
				return nullptr;

			ListNode* fast = head->next;
			ListNode* slow = head;

			while(fast && fast->next) {
				fast = fast->next->next; 
				slow = slow->next;
			} 

			/* new_head 不能为 nullptr */
			ListNode* new_head = slow->next;
			slow->next = nullptr;

			return new_head;
		}

		ListNode* sortList(ListNode* head) {
			if (!head || !head->next)
				return head;
			
			ListNode* head_right = split(head);

			ListNode* p1 = sortList(head);
			ListNode* p2 = sortList(head_right);

			return merge(p1, p2);
		}

		ListNode* merge(ListNode* l1, ListNode* l2) {
			ListNode dump(0);

			ListNode *curr = &dump;
			while(l1 && l2) {
				if (l1->val >= l2->val) {
						/*  这里不用主动断开next */
						curr->next = l2; 
						curr = l2;
						l2 = l2->next;
				} else {
						curr->next = l1; 
						curr = l1;
						l1 = l1->next;
				}
			}

			if (l1) {
				curr->next = l1;
			}

			if (l2) {
				curr->next = l2;
			}

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
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	b->next = a;
	ListNode *c = new ListNode(3);
	c->next = b;
	ListNode *d = new ListNode(4);
	d->next = c;

	Solution *test = new Solution();
	test->printList(d);
	ListNode *head =  test->sortList(d);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	
}

