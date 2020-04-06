/*
 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:
输入:
[
	1->4->5,
  	1->3->4,
  	2->6
]
		
输出: 1->1->2->3->4->4->5->6
*/
#include <vector>
#include <iostream>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
	int val;
 	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int v_len = lists.size();

		if (v_len == 0)
			return 0;

		if (v_len == 1)
			return lists[0];

		while (v_len > 1) {
			int k = (v_len + 1) / 2;
			std::cout << "v_len: " << v_len << " k: " << k << std::endl;
			for (int i = 0; i < v_len / 2; ++i) {
				lists[i] = mergeTwoLists(lists[i], lists[i+k]);
				std::cout << "print i: " << i << std::endl;
				printList(lists[i]); 
			} // for

			v_len = k;
		}  // while
	
		// error ideas
		/*
		while (v_len != 0) {
			int k = v_len / 2;
			std::cout << "v_len: " << v_len << " k: " << k << std::endl;
			for (int i = 0; i < v_len / 2; ++i) {
				lists[i] = mergeTwoLists(lists[i], lists[i+k]);
				std::cout << "print i: " << i << std::endl;
				printList(lists[i]); 
			} // for

			v_len = k;
		}  // while
		*/
		
		return lists[0];
	} 
							        

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 == NULL)
				return NULL;
		else if (l1 == NULL)
				return l2;
		else if (l2 == NULL)
				return l1;

		ListNode fake_node(-1);

		ListNode *pos = &fake_node;
		ListNode *next = NULL;

		while(l1 != NULL && l2 != NULL) {
			//std::cout << "l1->val: " << l1->val << " l2->val: " << l2->val << std::endl;
			if (l1->val < l2->val) {
				//std::cout << "what1\n";

				next = l1->next;

				pos->next = l1;
				l1->next = NULL;
				pos = l1;

				l1 = next;;
			} else {
				//std::cout << "what2\n";

				next = l2->next;

				pos->next = l2;
				l2->next = NULL;
				pos = l2;

				l2 = next;
			} // if

				
		} // while

		if (l1 != NULL) {
			pos->next = l1;	
		}

		if (l2 != NULL) {
			pos->next = l2;	
		}

		return  fake_node.next;
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
	ListNode *a_1 = new ListNode(1);
	ListNode *a_2 = new ListNode(4);
	ListNode *a_3 = new ListNode(5);
	a_1->next = a_2;
	a_2->next = a_3;

	ListNode *b_1 = new ListNode(1);
	ListNode *b_2 = new ListNode(3);
	ListNode *b_3 = new ListNode(4);
	b_1->next = b_2;
	b_2->next = b_3;
	
	ListNode *c_1 = new ListNode(2);
	ListNode *c_2 = new ListNode(6);
	c_1->next = c_2;
	
	/*
	ListNode *d_1 = new ListNode(7);
	ListNode *d_2 = new ListNode(8);
	d_1->next = d_2;
	*/

	Solution *test = new Solution();
	std::cout << "list1" << std::endl;
	test->printList(a_1);
	std::cout << "list2" << std::endl;
	test->printList(b_1);
	std::cout << "list3" << std::endl;
	test->printList(c_1);
	//std::cout << "list4" << std::endl;
	//test->printList(d_1);

	vector<ListNode*> v_list;
	v_list.push_back(a_1);
	v_list.push_back(b_1);
	v_list.push_back(c_1);
	//v_list.push_back(d_1);

	ListNode *head =  test->mergeKLists(v_list);	
	std::cout << "finish." << std::endl;
	test->printList(head);
	test->freeList(head);

	return 0;	

}


