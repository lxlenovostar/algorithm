#include <stdio.h>
#include <stdlib.h>

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *       int val;
 *       struct ListNode *next;
 * };
 */
struct ListNode {
	int val;
    struct ListNode *next;
};


struct ListNode* reverseList(struct ListNode* head) {
	return NULL;
}

void print_list() {

}

int main()
{
	struct ListNode *a1 = (struct ListNode*)malloc(sizeof(struct ListNode)); 
	a1->val = 1;

	struct ListNode *a2 = (struct ListNode*)malloc(sizeof(struct ListNode)); 
	a2->val = 2;
	a1->next = a2;

	struct ListNode *a3 = (struct ListNode*)malloc(sizeof(struct ListNode)); 
	a3->val = 3;
	a2->next = a3;

	struct ListNode *a4 = (struct ListNode*)malloc(sizeof(struct ListNode)); 
	a4->val = 4;
	a3->next = a4;

	struct ListNode *a5 = (struct ListNode*)malloc(sizeof(struct ListNode)); 
	a5->val = 5;
	a4->next = a5;
	a5->next = NULL;

	print_list(a1);
	free_list(a1);

	return 0;
}

