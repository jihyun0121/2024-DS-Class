#include <stdlib.h>
#include <stdio.h>
#define SIZE 1000000

int main(void) {
	int* a = (int*)malloc(sizeof(int) * SIZE);
	a[0] = 10;
	printf("%d\n", a[0]);
	free(a);
	return 0;
}