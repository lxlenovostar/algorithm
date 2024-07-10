#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == nullptr)
			return true;
		
		stack<int> tmp_stack;
		for (ListNode *tmp = head; tmp != nullptr; tmp = tmp->next) {
			tmp_stack.push(tmp->val);
		}
		
		for (ListNode *tmp = head; tmp != nullptr; tmp = tmp->next) {
			int value = tmp_stack.top();
			tmp_stack.pop();
			if (value != tmp->val)
				return false;
		}

		return true;
    }
};

int main() {
	ListNode *a1 = new ListNode(1);	
	ListNode *a2 = new ListNode(2);	
	ListNode *a3 = new ListNode(2);	
	ListNode *a4 = new ListNode(1);	

	a1->next = a2;
	a2->next = a3;
	a3->next = a4;

	ListNode *tmp = a1;
	for (; tmp != nullptr; tmp = tmp->next) {
		std::cout << tmp->val << " ";
	}
	std::cout << std::endl;

	Solution *test = new Solution();
	std::cout << test->isPalindrome(a1) << std::endl;

	return 0;
}


