/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
 	int val;
 	struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	} 
 	
	/*
	struct ListNode *result = head->next;

	while((head != NULL) && (head->next != NULL)) {
		struct ListNode* next_head = head->next->next;
		struct ListNode* tmp_next = head->next;
		head->next = next_head;
		tmp_next->next = head;

		head = next_head;
	}
	*/

	struct ListNode fake_head;
	fake_head.val = 0;
	fake_head.next = head;

	struct ListNode *p1 = &fake_head;
	struct ListNode *p2 = head;
	
	while((p2 != NULL) && (p2->next != NULL)) {
		struct ListNode *p3 = p2->next;
		struct ListNode* tmp_next = p3->next;

		printf("before p1:%d, p2:%d, p3:%d\n", p1->val, p2->val, p3->val);

		p1->next = p3;
		p3->next = p2;
		p2->next = tmp_next;

		p1 = p2;
		p2 = tmp_next;
		
		//if (p3 != NULL)
		//	printf("end p1:%d, p2:%d, p3:%d\n", p1->val, p2->val, p3->val);
	}

	return fake_head.next;
}

void print_list(struct ListNode *head) {
	printf("print begin\n");
	while(head != NULL) {
		printf("%d\n", head->val);
		head = head->next;
	}
	printf("print end\n");
}

void free_list(struct ListNode *head) {
	struct ListNode *tmp = head;
	printf("free begin, head:%p\n", head);
	while(head != NULL) {
		printf("%d\n", head->val);
		tmp = head;
		head = head->next;
		free(tmp);
	}
	printf("free end\n");
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
	struct ListNode *result = swapPairs(a1);
	print_list(result);
	free_list(result);

	return 0;
}

