/*
 * 82. Remove Duplicates from Sorted List II
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 * 
 * TODO:
 * 1.如果head和head->next一样，删除head,pre->next等于head->next
 * 2.如果head需要删除的head是真正的head, 那么result 就等于head->next
 * 3.
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

			ListNode dummy(0);
			dummy.next = head;
			ListNode* prev = &dummy;
			ListNode* p = head;

			while(p && p->next) {
				if (p->val == p->next->val) {
					int val = p->val;
					ListNode* tmp = p->next->next;

					delete p->next;
					delete p;
					while (tmp) {
						if (tmp->val != val)
							break;


						ListNode* need_d = tmp;
						tmp = tmp->next;
						delete need_d;
					}
					prev->next = tmp;
					p = tmp;
				} else {
					prev = p;
					p = p->next;
				}
			}
			
			/*
			 * 处理返回值很棒!
			 * */	
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
	ListNode *a = new ListNode(2);
	ListNode *b = new ListNode(2);
	b->next = a;
	/*
	ListNode *c = new ListNode(1);
	c->next = b;
	ListNode *d = new ListNode(1);
	d->next = c;
	*/

	Solution *test = new Solution();
	test->printList(b);
	ListNode *head =  test->deleteDuplicates(b);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	
}

