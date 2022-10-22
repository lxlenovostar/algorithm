/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
		bool find = false;

        while (fast && fast->next && slow) {
            fast = fast->next->next; 
            slow = slow->next;

			if (fast == slow) {
				find = true;
				break;
			}
        }

		if (!find)
			return nullptr;

		ListNode *new_start = head;

		std::cout << "what slow val:" << slow->val << std::endl;
		std::cout << "what fast val:" << fast->val << std::endl;

		while (new_start && slow && new_start != slow) {
			new_start = new_start->next;		
			slow = slow->next;
		}

		return slow;
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

int main() {
	/*
	ListNode *a = new ListNode(-4);
	ListNode *b = new ListNode(0);
	b->next = a;
	ListNode *c = new ListNode(2);
	c->next = b;
	ListNode *d = new ListNode(3);
	d->next = c;
    a->next = c;
	*/
	ListNode *d = new ListNode(1);

	Solution *test = new Solution();
	ListNode *head =  test->detectCycle(d);	
	std::cout << "finish." << head->val << std::endl;

    return 0;
}