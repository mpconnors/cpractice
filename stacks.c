#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//array implementation of a stack

struct Stack{
	int top;
	unsigned int capacity;
	int *array;
};

struct Stack* createStack(unsigned int capacity){
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

int isFull(struct Stack* stack){
	if(stack->top == stack->capacity-1){
		return 1;
	}
	else{
		return 0;
	}
}

int isEmpty(struct Stack* stack){
	if(stack->top == -1){
		return 1;
	}
	else{
		return 0;
	}
}

void push(struct Stack* stack, int data){
	if(isFull(stack)){
		return;
	}
	stack->top = stack->top + 1;
	stack->array[stack->top] = data;
	printf("%d pushed to stack\n", data);
}

int pop(struct Stack* stack){
	if(isEmpty(stack)){
		return INT_MIN;
	}
	int popped = stack->array[stack->top];
	stack->top = stack->top - 1;
	printf("%d popped from stack\n", popped);
	return popped;
}

int peek(struct Stack* stack){
	if(isEmpty(stack)){
		return INT_MIN;
	}
	int peeked = stack->array[stack->top];
	printf("%d on top of stack\n", peeked);
	return peeked;
}

int main(void){
	struct Stack* stack = createStack(100);
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	push(stack, 155);
	push(stack, 66);
	pop(stack);
	peek(stack);
	free(stack);

}