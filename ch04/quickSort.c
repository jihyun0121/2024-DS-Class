#include <stdio.h>
#include <stdlib.h>

void quickSort(int a[], int left, int right) {
	int i = left, j = right, pivot = a[left], temp;

	//		>=
	if (left < right) {
		while (i < j) {
			while (i < right && a[i] <= pivot) i++;
			while (j > left && a[j] >= pivot) j--;
			if (i < j) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}

		a[left] = a[j];
		a[j] = pivot;

		quickSort(a, left, j - 1);
		quickSort(a, j + 1, right);
	}
}

int main(void) {
	int a[] = { 7, 13, 51, 30, 25, 17, 56, 1, 28, 21 };
	int i, n = sizeof(a) / sizeof(int);

	quickSort(a, 0, n-1);

	for (int i = 0; i < n; i++)
		printf("%5d", a[i]);

	return 0;
}