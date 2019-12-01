/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

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

int compare_list(struct ListNode1 *head1, struct ListNode1 *head2) {
	if (head1 == NULL && head2 == NULL) {	
		return true;
	}

	if (head1 == NULL || head2 == NULL) {
		printf("what2\n");
		return false;
	}

	while(head1 != NULL && head2 != NULL)
	{
		if (head1->val != head2->val) {
			printf("what3\n");
			return false;
		}

		head1 = head1->next;
		head2 = head2->next;
	}

	if (head2 != head1) {
		printf("what4\n");
		return false;
	}

	return true;
}

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

static void pop_stack(struct Stack *stack) {
	struct ListNode1 *tmp = stack->stack_tail; 
	if (tmp == NULL)
		return;

	stack->stack_tail = tmp->pre;

	if (tmp->pre == NULL) {
		stack->stack_head = NULL;
	} else
		stack->stack_tail->next = NULL;

	tmp->pre = NULL;
	tmp->next = NULL;
	free(tmp);
}

int backspaceCompare(char *S, char *T) {
	if (S == NULL || T == NULL){
		return false;
	}
	
	if (S == NULL && T == NULL)	{
		return true;
	}

	struct Stack s_stack;
	struct Stack t_stack;
	char *pos;

	s_stack.stack_head = NULL;
	s_stack.stack_tail = NULL;
	t_stack.stack_head = NULL;
	t_stack.stack_tail = NULL;

	for (pos = S; *pos != '\0'; pos++)  {
		if (*pos != '#')
			push_stack(&s_stack, *pos);
		else 
			pop_stack(&s_stack);
	}

	for (pos = T; *pos != '\0'; pos++)  {
		if (*pos != '#')
			push_stack(&t_stack, *pos);
		else 
			pop_stack(&t_stack);
	}

	return compare_list(s_stack.stack_head, t_stack.stack_head);
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
	
	printf("ret:%d\n", backspaceCompare("ab#c", "ab#c"));
	printf("ret:%d\n", backspaceCompare("ab##", "c#d#"));
	printf("ret:%d\n", backspaceCompare("a##c", "#a#c"));
	printf("ret:%d\n", backspaceCompare("a#c", "b"));
	printf("ret:%d\n", backspaceCompare("isfcow#", "isfco#w#"));

	return 0;
}

