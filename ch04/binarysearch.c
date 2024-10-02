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

	printf("찾을 값 : ");
	scanf_s("%d", &key);
	index = binarySearch(a, n, key);

	if (index >= 0) printf("%d를(을) %d위치에서 찾음!\n", key, index);
	else printf("%d은(는) 없는 데이터임!\n");												//말투 되게 다긍이 같다
	return 0;
}