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
	struct ListNode *stack = NULL;

	while(head->next != NULL) {
		printf("reverseList:%d\n", head->val);
		struct ListNode *next = head->next;

		if (stack == NULL) { 
			stack = head;
			stack->next = NULL;
		}
		else {
			head->next = stack;	
			stack = head;
		}

		head = next;
	}
		
	return stack;
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
	printf("free begin\n");
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
	print_list(reverseList(a1));
	free_list(a1);

	return 0;
}

