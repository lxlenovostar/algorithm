/*
 * 21. Merge Two Sorted Lists
 *
 * Merge two sorted linked lists and return it as a new list. The new list should be made by 
 * splicing together the nodes of the first two lists.
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
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			if (l1 && !l2)
				return l1;
			else if (l2 && !l1)
				return l2;
			else if (!l1 && !l2)
				return NULL;
			else {
				ListNode *head = NULL;		
				ListNode *current = NULL;
				
				if (l1->val <= l2->val) {
					head = l1;
					current = l1;
					l1 = l1->next;
				} else {
					head = l2;
					current = l2;
					l2 = l2->next;
				}

				while(l1 != NULL && l2 != NULL) {
					if (l1->val <= l2->val) {
						current->next = l1;
						current = l1;
						l1 = l1->next;
					}
					else { 	
						current->next = l2;
						current = l2;
						l2 = l2->next;
					}
				}

				if (l1 && !l2)
					current->next = l1;
				else if (l2 && !l1)
					current->next = l2;

				return head;
			}
		}
	
		ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
			/*
			 * 实现的优点:
			 * 1.处理头指针很棒!
			 * 2.没有那么多的if判断.
			 * */
			ListNode dummy(0);
			ListNode* p = &dummy;
			
			while(l1 && l2) {
				int val1 = l1->val;
				int val2 = l2->val;
						
				//哪个节点小， 就挂载， 同时移动到下一个节点
				if(val1 < val2) {
					p->next = l1;
					p = l1;
					l1 = l1->next;
				} else {
					p->next = l2;
					p = l2;
					l2 = l2->next;
				}
			} 
						
			//这里处理还未挂载的节点
			if(l1) {
				p->next = l1;
			} else if(l2) {
				p->next = l2;
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
	ListNode *a = new ListNode(3);
	ListNode *b = new ListNode(2);
	b->next = a;
	ListNode *c = new ListNode(4);
	ListNode *d = new ListNode(1);
	d->next = c;

	Solution *test = new Solution();
	std::cout << "list1" << std::endl;
	test->printList(b);
	std::cout << "list2" << std::endl;
	test->printList(d);
	ListNode *head =  test->mergeTwoLists(NULL, NULL);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	
}

