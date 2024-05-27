#include <stdio.h>
#define SIZE 6

int queue[SIZE];
int rear = -1, front = 0;

int cnt = 0;	//선형 큐에서 환형 큐로 바꾸기 위한 코드

int add(int data) {
	if (cnt == SIZE) {	//선형 큐에서 환형 큐로 바꾸기 위한 코드 (cnt == SIZE)
		printf("Queue is Full!\n");
		return -1;
	}queue[++rear % SIZE] = data;	//선형 큐에서 환형 큐로 바꾸기 위한 코드 ( % SIZE)
	cnt++;	//선형 큐에서 환형 큐로 바꾸기 위한 코드
	return 0;

}
int delete(void) {
	if (cnt == 0) {	//선형 큐에서 환형 큐로 바꾸기 위한 코드 (cnt == 0)
		printf("Queue is Empty!\n");
		return -1;
	}
	cnt--;	//선형 큐에서 환형 큐로 바꾸기 위한 코드
	return queue[front++ % SIZE];	//선형 큐에서 환형 큐로 바꾸기 위한 코드 ( % SIZE)
}

int main(void) {
	add(10); add(20); add(30); add(40); add(50);
	printf("%d\n", delete());
	printf("%d\n", delete());
	printf("%d\n", delete());
	printf("%d\n", delete());
	printf("%d\n", delete());
	printf("%d\n", delete());

	add(60);	//정상적으로 처리
	add(70);	//index가 0이 됨

	return 0;
}