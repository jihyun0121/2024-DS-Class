#include <stdio.h>

void heapSort(int a[], int n) {
	int i, parent, child, value, size = n;

	//�ִ� �� ����
	for (i = n / 2; i >= 1; i--) {
		value = a[i];
		parent = i;
		while ((child = parent * 2) <= n) {
			//�߿�!!!	!!������ ��!!
			if (child + 1 <= n && a[child] < a[child + 1]) child++;
			if (value < a[child]) {
				a[parent] = a[child];
				parent = child;
			}
			else break;
		}
		a[parent] = value;
	}

	//����(�ִ� �̵� �� �� �籸��)
	while (n > 1) {
		value = a[n];	//�ִ� �̵�
		a[n--] = a[1];
		parent = 1;		//�ִ� �� �籸��
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

	printf("������: ");
	for (i = 1; i < n; i++)	printf("%4d", a[i]);
	printf("\n\n");

	heapSort(a, n - 1);

	printf("\n������: ");
	for (i = 1; i < n; i++)	printf("%4d", a[i]);
	printf("\n\n");

	return 0;
}