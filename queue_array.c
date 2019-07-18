#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Simple array implementation of a queue

struct Queue{
	int front, rear, size;
	unsigned int capacity;
	int* array;
};

struct Queue* createQueue(unsigned int capacity){
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = 0;
	q->size = 0;
	q->rear = 0;
	q->capacity = capacity;
	q->array = (int *)malloc(sizeof(int) * capacity);
	return q;
}

int isFull(struct Queue* q){
	return q->size == q->capacity;
}

int isEmpty(struct Queue* q){
	return q->size == 0;
}

int arrayBoundError(struct Queue* q){
	return q->rear == q->capacity;
}

void enQueue(struct Queue* q, int item){
	if(isFull(q) || arrayBoundError(q)){
		printf("Error. Queue is full.\n");
		return;
	}
	q->array[q->rear] = item;
	q->rear++;
	q->size++;
	return;
}

int deQueue(struct Queue* q){
	if(isEmpty(q) || arrayBoundError(q)){
		return INT_MIN;
	}
	printf("%d dequeued from queue\n", q->array[q->front]);
	int dq = q->array[q->front];
	q->front++;
	q->size--;
	return dq;
}

void printQueue(struct Queue* q){
	for(int i = q->front; i < q->rear; i++){
		printf("%d\n", q->array[i]);
	}
}
int main(void){
	struct Queue* q = createQueue(10);
	enQueue(q,5);
	enQueue(q,8);
	enQueue(q,7);
	enQueue(q,13);
	printQueue(q);
	printf("***************\n\n");
	deQueue(q);
	deQueue(q);
	printf("***************\n\n");
	printQueue(q);

	free(q->array);
	free(q);
	return 0;
}