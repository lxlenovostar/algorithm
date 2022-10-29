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
	private:
		struct Node {
			int val;
			ListNode *node;

			bool operator < (const Node& rhs) const {
				return val > rhs.val;
			}
		};
	public:
		ListNode* mergeKLists(std::vector<ListNode*>& lists) {
			if (lists.size() == 0) return nullptr;

			ListNode dummy(0);
			ListNode *tail = &dummy;
			std::priority_queue<struct Node> q;
			for (auto& item : lists) {
					if (item) {
						q.push({item->val, item});
						item = item->next;
					}
			}

			while(!q.empty()) {
				struct Node n = q.top();
				q.pop();

				tail->next = n.node;
				tail = tail->next;

				ListNode *next =  n.node->next;
				if (next)
					q.push({next->val, next});
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

