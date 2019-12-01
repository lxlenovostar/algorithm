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

struct ListNode {
	int val;
 	struct ListNode *next;
 	struct ListNode *pre;
};

struct Stack {
	struct ListNode *stack_head;
	struct ListNode *stack_tail;
};

typedef struct {
	struct Stack input;
	struct Stack output;
} MyQueue;

static void push_stack(struct Stack *stack, char val)
{
	struct ListNode *tmp = (struct ListNode*)malloc(sizeof(struct ListNode)); 
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

static int pop_stack(struct Stack *stack) {
	struct ListNode *tmp = stack->stack_tail; 
	if (tmp == NULL)
		return -1;

	stack->stack_tail = tmp->pre;

	if (tmp->pre == NULL) {
		stack->stack_head = NULL;
	} else
		stack->stack_tail->next = NULL;

	int ret = tmp->val;
	tmp->pre = NULL;
	tmp->next = NULL;
	free(tmp);
	return ret;
}

static int peek_stack(struct Stack *stack) {
	struct ListNode *tmp = stack->stack_tail; 
	if (tmp == NULL)
		return -1;

	return tmp->val;
}

/** Initialize your data structure here. */

MyQueue* myQueueCreate() { 
	MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));

	queue->input.stack_head = NULL;
	queue->input.stack_tail = NULL;

	queue->output.stack_head = NULL;
	queue->output.stack_tail = NULL;

	return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	push_stack(&obj->input, x);	
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	
	if (obj->output.stack_tail != NULL) {
		return pop_stack(&obj->output);
	} else { 
		while (obj->input.stack_tail != NULL) {
			int tmp = pop_stack(&obj->input);
			push_stack(&obj->output, tmp);
		}

		return pop_stack(&obj->output);
	}
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (obj->output.stack_tail != NULL) {
		return peek_stack(&obj->output);
	} else { 
		while (obj->input.stack_tail != NULL) {
			int tmp = pop_stack(&obj->input);
			push_stack(&obj->output, tmp);
		}

		return peek_stack(&obj->output);
	}
}

/** Returns whether the queue is empty. */
int myQueueEmpty(MyQueue* obj) {
	if (obj->input.stack_tail == NULL && obj->output.stack_tail == NULL)	
		return 1;
	else 
		return 0;
}

void free_stack(struct ListNode *head) {
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

void print_stack(struct ListNode *head) {
	struct ListNode *tmp = head;
	printf("print begin, head:%p\n", head);
	while(tmp != NULL) {
		printf("%d\n", tmp->val);
		tmp = tmp->next;
	}
	printf("print end\n");
}

void myQueueFree(MyQueue* obj) {
	free_stack(obj->input.stack_head);
	free_stack(obj->output.stack_head);
}

int main()
{
	/**
 	 * Your MyQueue struct will be instantiated and called as such:
	 */
	MyQueue* obj = myQueueCreate();
    myQueuePush(obj, 1);
    myQueuePush(obj, 2);
    myQueuePush(obj, 3);
 
	print_stack(obj->input.stack_head);

    int param_2 = myQueuePop(obj);
	printf("param_2:%d\n", param_2);
	print_stack(obj->input.stack_head);
	print_stack(obj->output.stack_head);
 	int param_3 = myQueuePeek(obj);
	printf("param_3:%d\n", param_3);
	print_stack(obj->output.stack_head);
 	int param_4 = myQueueEmpty(obj);
	printf("param_4:%d\n", param_4);

	myQueueFree(obj);

	return 0;
}

