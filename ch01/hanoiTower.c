#include <stdio.h>
void HanoiTower(int n, char a, char b, char c) {	//a는 출발지, b는 경유지, c는 도착지 변수
	if (n == 1)printf("원판 %d, %c -> %c\n", n, a, c);
	else {
		HanoiTower(n - 1, a, c, b);
		printf("원판 %d, %c -> %c\n", n, a, c);
		HanoiTower(n - 1, b, a, c);
	}
}
int main(void) {
	int n = 4;

	HanoiTower(n, 'A', 'B', 'C');	//A는 출발지, B는 경유지, C는 도착지 변수

	return 0;
}