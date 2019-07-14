#include <stdio.h>

void swap(int *x, int *y);

int main(void){
	// int x = 7;
	// printf("x is %d\n", x);
	// x = 14;
	// printf("x is %d\n", x);

	// int *aptr = &x;
	// printf("%x\n", aptr);
	// printf("x is %d\n", *aptr);
	// *aptr = 21;
	// printf("x is now %d\n", x);

	// int somenumbers[5];
	// int *ptr = somenumbers;
	// int v = 2;

	// for(;ptr<&somenumbers[5];ptr++){
	// 	*ptr = v;
	// 	v = v * 2;
	// }

	// int i;
	// for(i = 0; i < 5; i++){
	// 	printf("%d\n", somenumbers[i]);
	//}

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