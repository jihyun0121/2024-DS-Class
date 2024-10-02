#include <stdio.h>

int binarySearch(int a[], int n, int key) {
	int left = 0, mid, right = n - 1;

	while (left <= right) {
		mid = (left + right) / 2;
		if (key == a[mid]) return mid;;
		if (key > a[mid]) left = mid + 1;
		else right=mid-1;
	}
	return -1;
}

int main(void) {
	int i, index, key, n;
	int a[] = { 3, 7, 10, 12, 14, 18, 21, 33, 35, 48 };
	n = sizeof(a) / sizeof(int);

	printf("ã�� �� : ");
	scanf_s("%d", &key);
	index = binarySearch(a, n, key);

	if (index >= 0) printf("%d��(��) %d��ġ���� ã��!\n", key, index);
	else printf("%d��(��) ���� ��������!\n");												//���� �ǰ� �ٱ��� ����
	return 0;
}