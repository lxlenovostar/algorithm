#include <iostream>
#include <vector>
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
		ListNode* mergeKLists(std::vector<ListNode*>& lists) {
			if (lists.size()  == 1)
				return lists[0];
            if (lists.size() == 0)
                return nullptr;
			
			int n = lists.size();
			while( n > 1) {
				std::cout << "n: " << n << std::endl;
				for (int i = 0; i < n/2; ++i)
				{
					lists[i] =  mergeTwoLists(lists[i], lists[n-i-1]);
				}
				n = (n+1)/2;
			}

			return lists[0];
    	}

		ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
			ListNode dummy(0);
			ListNode* p = &dummy;

			while(l1 && l2) {
				int val1 = l1->val;
				int val2 = l2->val;
				
				if (val1 <= val2) {
					//std::cout << "val1: " << val1 << std::endl;
					p->next = l1;
					p = p->next;
					l1 = l1->next;
				} else {
					//std::cout << "val2: " << val2 << std::endl;
					p->next = l2;
					p = p->next;
					l2 = l2->next;
				}
			} 

			if (l1 == nullptr) {
				std::cout << "l1" << std::endl;
				p->next = l2;
			}
			else { 
				std::cout << "l2" << std::endl;
				p->next = l1;
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
	std::vector<ListNode*>  l;
	l.push_back(b);
	l.push_back(d);
	ListNode *head =  test->mergeKLists(l);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	
}

