#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Program to implement a queue using two array stacks. Costly enqueue, O(n); dequeue O(1)

struct Stack{
	int top;
	unsigned int capacity;
	int *array;
};

struct s_queue{
	struct Stack* stack2;
	struct Stack* stack1;
};

int isEmpty(struct Stack* stack){
	return stack->top == -1;
};


int isFull(struct Stack* stack){
	return stack->top == stack->capacity-1;
};

struct Stack* createStack(unsigned int capacity){
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
};

struct s_queue* createQueue(unsigned int capacity){
	struct Stack* s1 = createStack(capacity);
	struct Stack* s2 = createStack(capacity);

	struct s_queue* q = (struct s_queue*)malloc(sizeof(struct s_queue));
	q->stack1 = s1;
	q->stack2 = s2;

	return q;
};

void push(struct Stack* stack, int data){
	if(isFull(stack)){
		return;
	}
	stack->top = stack->top + 1;
	stack->array[stack->top] = data;
	return;
}

int pop(struct Stack* stack){
	if(isEmpty(stack)){
		return INT_MIN;
	}
	int popped = stack->array[stack->top];
	stack->top = stack->top - 1;
	return popped;
}


//costly enqueue
void enQueue(struct s_queue* q, int data){

	if(isEmpty(q->stack1)){
		q->stack1->array[++q->stack1->top] = data;
		return;
	}
	if(isFull(q->stack1)){
		printf("Error: queue is at capacity");
		return;
	}

	//transfer all data from s1 to s2, add new data to s1, move s2 data back into s1
	while(isEmpty(q->stack1) != 1){
		push(q->stack2, pop(q->stack1));
	}
	push(q->stack1, data);
	while(isEmpty(q->stack2) != 1){
		push(q->stack1, pop(q->stack2));
	}
	return;

}

int deQueue(struct s_queue* q){
	int rem = pop(q->stack1);
	printf("%d removed from front of queue\n", rem);
	return rem;
}

void printQueue(struct s_queue* q){
	for(int i = 0; i <= q->stack1->top; i++){
		printf("%d\n", q->stack1->array[i]);
	}

}

int freeQueue(struct s_queue* q){
	free(q->stack1);
	free(q->stack2);
	free(q);
	return 0;
}

int main(void){
	int capacity = 100;

	struct s_queue* q = createQueue(capacity);

	enQueue(q, 30);
	enQueue(q, 40);
	enQueue(q, 33450);
	enQueue(q, 67);
	enQueue(q, 99);
	printQueue(q);
	deQueue(q);
	deQueue(q);
	printQueue(q);
	freeQueue(q);

	return 0;
}