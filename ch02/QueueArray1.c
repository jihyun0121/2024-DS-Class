#include <stdio.h>
#define SIZE 6

int queue[SIZE];
int rear = -1, front = 0;
int add(int data) {
	if (rear == SIZE - 1) {
		printf("Queue is Full!\n");
		return -1;
	}queue[++rear] = data;
	return 0;

}
int delete(void) {
	if (rear < front) {
		printf("Queue is Empty!\n");
		return -1;
	}
	return queue[front++];
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
	add(70);	//overflow 발생

	return 0;
}