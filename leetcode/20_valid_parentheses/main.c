/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int true = 1;
int false = 0;

struct ListNode1 {
	char val;
 	struct ListNode1 *next;
 	struct ListNode1 *pre;
};

struct Stack {
	struct ListNode1 *stack_head;
	struct ListNode1 *stack_tail;
};

static void push_stack(struct Stack *stack, char val)
{
	struct ListNode1 *tmp = (struct ListNode1*)malloc(sizeof(struct ListNode1)); 
	tmp->val = val;
	
	if (stack->stack_head == NULL && stack->stack_tail == NULL)
	{
		stack->stack_head = stack->stack_tail = tmp;
		tmp->next = NULL;
		tmp->pre = NULL;
	} else {
		stack->stack_tail->next = tmp;
		tmp->pre = stack->stack_tail;
		tmp->next = NULL;		
		stack->stack_tail = tmp;
	}
} 

static char pop_stack(struct Stack *stack) {
	struct ListNode1 *tmp = stack->stack_tail; 
	if (tmp == NULL) {
		//can't arrive here.
		return '\0';
	}

	stack->stack_tail = tmp->pre;

	if (tmp->pre == NULL) {
		stack->stack_head = NULL;
	} else
		stack->stack_tail->next = NULL;

	char ret = tmp->val;
	tmp->pre = NULL;
	tmp->next = NULL;
	free(tmp);

	return ret;
}

static int empty_stack(struct Stack *stack) {
	if (stack->stack_tail == NULL)
		return 1;
	else 
		return 0;
}

int isValid(char *s) {
	if (s == NULL || strlen(s) == 0)	
		return 1;

	struct Stack stack;
	char *pos;
	for (pos = s; *pos != '\0'; pos++) {
		if (*pos == '(' ) {
			push_stack(&stack, ')');
		} else if (*pos == '[' ) {
			push_stack(&stack, ']');
		} else if (*pos == '{' ) {
			push_stack(&stack, '}');
		} else {
			char ret = pop_stack(&stack);
			printf("pos:%c, ret:%c\n", *pos, ret);
			if (ret != *pos)	
				return 0;
		}	
	}

	if (empty_stack(&stack) == 1)	
		return 1;
	else 
		return 0;
}


/*
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
*/

int main()
{
	/*
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
	*/

	printf("test1:%d\n", isValid("()[]{}"));	
	printf("test2:%d\n", isValid(""));	
	printf("test3:%d\n", isValid("{]"));	
	printf("test3:%d\n", isValid("()"));	

	return 0;
}

