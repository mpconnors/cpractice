#include <stdio.h>
#include <stdlib.h>

struct Node{
	int val;
	struct Node *next;
};

void printList(struct Node *n){
	while(n != NULL){
		printf("%d\n", n->val);
		n = n->next;
	}
};

void reverseList(struct Node **n){
	struct Node *prev;
	struct Node *curr;
	struct Node *next;

	prev = NULL;
	curr = *n;
	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;

	}
	*n = prev;
}

struct Node* anotherRev(struct Node *n){
	struct Node *list_to_rev = n->next;
	struct Node *reverse = n;
	reverse->next = NULL;
	struct Node *tmp;

	while(list_to_rev != NULL){
		tmp = list_to_rev;
		list_to_rev = list_to_rev->next;
		tmp->next = reverse;
		reverse = tmp;
	}
	return reverse;
}

void printrevList(struct Node *n){
	struct Node *prev = NULL;
	struct Node *curr = n;
	struct Node *next;

	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	n = prev;
	while(n != NULL){
		printf("%d\n", n->val);
		n = n->next;
	}

}

void freeList(struct Node *n){
	struct Node *tmp;

	while(n != NULL){
		tmp = n;
		n = n->next;
		free(tmp);
	}
}

void append(struct Node *n, int x){
	struct Node *new_node = NULL;
	struct Node *last;
	new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->val = x;
	new_node->next = NULL;

	while(n !=NULL){
		last = n;
		n=n->next;
	}
	last->next=new_node;
}

void pop(struct Node *n){
	struct Node *prev;
	struct Node *after;
	while(after != NULL){
		prev = n;
		n=n->next;
		after = n->next;
	}
	prev->next = NULL;

}

int main(void){
	struct Node *head = NULL;
	struct Node  *second = NULL;
	struct Node *third = NULL;

	//allocate 3 nodes in the heap
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));

	head->val = 10;
	head->next = second;

	second->val = 20;
	second->next = third;

	third->val = 30;
	third->next = NULL;

	
	// reverseList(&head);
	// printrevList(head);
	//head = anotherRev(head);
	append(head, 40);
	append(head, 66);
	append(head, 1003);
	printList(head);
	printf("\n ... \n");
	pop(head);
	printList(head);
	printf("\n ... \n");
	pop(head);
	printList(head);
	printf("\n ... \n");
	pop(head);
	printList(head);
	printf("\n ... \n");
	pop(head);
	printList(head);
	printf("\n ... \n");
	// printList(head);
	freeList(head);

	return 0;

}