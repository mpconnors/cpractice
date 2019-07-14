#include <stdio.h>

void swap(int *x, int *y);

int main(void){

	int a = 5;
	int b = 8;

	swap(&a,&b);
	printf("a is now %d\n b is now %d\n", a, b);

}

void swap(int *x, int *y){
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
	return;
}