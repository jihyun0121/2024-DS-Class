#include <stdio.h>
int euclid(int m, int n) {
	int r;

	while ((r = m % n) != 0) {
		m = n;
		n = r;
	}
	return n;
}

int main(void) {

	int m, n, t;

	printf("양의 정수 : ");
	scanf_s("%d", &m);
	printf("음의 정수 : ");
	scanf_s("%d", &n);

	if (m < n) { t = m; m = n; n = t; }
	printf("%d와 %d의 최대공약수 : %d\n", m, n, euclid(m, n));
	return 0;
}