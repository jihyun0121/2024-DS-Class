#include <stdio.h>

void heapSort(int a[], int n) {
	int i, parent, child, value, size = n;

	//최대 힙 구성
	for (i = n / 2; i >= 1; i--) {
		value = a[i];
		parent = i;
		while ((child = parent * 2) <= n) {
			//중요!!!	!!조심할 것!!
			if (child + 1 <= n && a[child] < a[child + 1]) child++;
			if (value < a[child]) {
				a[parent] = a[child];
				parent = child;
			}
			else break;
		}
		a[parent] = value;
	}

	//정렬(최댓값 이동 및 힙 재구성)
	while (n > 1) {
		value = a[n];	//최댓값 이동
		a[n--] = a[1];
		parent = 1;		//최대 힙 재구성
		while ((child = parent * 2) <= n) {
			if (child + 1 <= n && a[child] < a[child + 1]) child++;
			if (value < a[child]) {
				a[parent] = a[child];
				parent = child;
			}
			else break;
		}
		a[parent] = value;
		for (i = 1; i < size; i++)	printf("%5d", a[i]);
		printf("\n");
	}
}

int main(void) {
	int a[] = { 0, 21, 12, 9, 17, 3, 1, 20, 15, 25, 11 };
	int i, n = sizeof(a) / sizeof(int);

	printf("정렬전: ");
	for (i = 1; i < n; i++)	printf("%4d", a[i]);
	printf("\n\n");

	heapSort(a, n - 1);

	printf("\n정렬후: ");
	for (i = 1; i < n; i++)	printf("%4d", a[i]);
	printf("\n\n");

	return 0;
}