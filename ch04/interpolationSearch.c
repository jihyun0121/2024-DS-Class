#include <stdio.h>

int cnt = 0;
int interpolationSearch(int a[], int left, int right, int key) {
    int mid;

    while (left <= right) {
        cnt++;
        if (a[left] == a[right]) mid = left;
        else {
            mid = left + (right - left) * (key - a[left]) / (a[right] - a[left]);
            if (mid > right) mid = right;
            if (mid < left) mid = left;
        }

        if (key == a[mid]) return mid;
        else if (key < a[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return -1; // key�� ã�� ������ ��
}

int main(void) {
    int a[] = { 3, 6, 9, 12, 15, 18, 21, 24, 27, 30 };
    int n = sizeof(a) / sizeof(int);
    int index, key;

    printf("ã�� �� : ");
    scanf_s("%d", &key);
    index = interpolationSearch(a, 0, n - 1, key);
    if (index >= 0) printf("%d ��ġ���� %d ȸ ���Ͽ� ã��!\n", index, cnt);
    else printf("���� ��������!\n");
}
