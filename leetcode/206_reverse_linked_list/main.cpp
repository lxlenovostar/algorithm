/*
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
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
    ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)			
			return head;

		ListNode new_head(0);
		ListNode* next = head->next;

		if (next == nullptr) {		
			return nullptr;
		}

		while(head != nullptr && head->next != nullptr) {

			head->next = new_head.next;
			new_head.next = head;

			head = next;
			next = head->next;
		}

		head->next = new_head.next;
		new_head.next = head;

		return new_head.next;
    }
};

int main() {
	ListNode *a1 = new ListNode(1);	
	ListNode *a2 = new ListNode(2);	
	ListNode *a3 = new ListNode(3);	
	ListNode *a4 = new ListNode(4);	
	ListNode *a5 = new ListNode(5);	

	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;

	ListNode *tmp = a1;
	for (; tmp != nullptr; tmp = tmp->next) {
		std::cout << tmp->val << " ";
	}
	std::cout << std::endl;


	Solution *obj = new Solution();
	ListNode *ret = obj->reverseList(a1);

	for (; ret != nullptr; ret = ret->next) {
		std::cout << ret->val << " ";
	}
	std::cout << std::endl;

	return 0;
}


