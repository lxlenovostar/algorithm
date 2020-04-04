#include <iostream>
#include <set>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
 	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
	public:
    bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return false;

		ListNode *fast = head;
		ListNode *slow = head;

		while (fast->next != NULL && fast->next->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;

			if (fast == slow)
				return true;
		
		}

		return false;

		/*
		ListNode *next_1 = head->next;
		if (next_1 == NULL)
			return true;

		ListNode *next_2 = head->next->next;

		while(next_1 != NULL &&  next_2 != NULL) {
			//std::cout << "next_1: " << next_1->val << " next_2: " << next_2->val << std::endl;

			if (next_1 == next_2)
				return true;

			next_1 = next_1->next;
			ListNode *next = next_2->next;
			if (next == NULL)
				return false;
			else 
				next_2 = next->next;
		}

		return false;
		*/
							        
	}

	bool hasCycle_set(ListNode *head) {
		if (head == NULL || head->next == NULL) {
			return false;
		}

		set<int> visited;

		while(head != NULL)	 {
			if (visited.find(head->val) == visited.end()) {
				visited.insert(head->val);
			} else {
				return true;
			}

			head = head->next;
		}

		return false;
	}
};


int main() {
	// head = [3,2,0,-4], pos = 1
	/*
	ListNode *n_1 = new ListNode(3);
	ListNode *n_2 = new ListNode(2);
	ListNode *n_3 = new ListNode(0);
	ListNode *n_4 = new ListNode(-4);

	n_1->next = n_2;
	n_2->next = n_3;
	n_3->next = n_4;
	n_4->next = n_2;
	*/
	
	ListNode *n_1 = new ListNode(1);
	ListNode *n_2 = new ListNode(2);
	n_1->next = n_2;

	Solution *obj = new Solution();
	std::cout << obj->hasCycle(n_1) << std::endl;

	return 0;
}


