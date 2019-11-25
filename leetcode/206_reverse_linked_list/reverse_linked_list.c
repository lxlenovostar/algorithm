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

	while(head != NULL) {
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

struct ListNode* reverseList2(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return NULL;
	} else {
		struct ListNode *p1 = head;
		struct ListNode *p2 = head->next;
		struct ListNode *p3 = NULL;

		while (p2) {
			p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
		}

		head->next = NULL;
		return p1;
	}	
}

struct ListNode* reverseList3(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	} else {
		struct ListNode* new_head = reverseList3(head->next);

		head->next->next = head;
		head->next = NULL;

		return new_head;
	}
}

/*
struct ListNode* reverseList_2(struct ListNode* head) {
		if (head == NULL)
			return NULL;
		else {
			struct ListNode *stack = head;
			reverseList2(head->next, stack);	
			return stack;
		}
}
*/

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
	struct ListNode *result = reverseList3(a1);
	print_list(result);
	free_list(result);

	return 0;
}

