#include <stdio.h>
#define SIZE 6

//전역에서 선언
int stack[SIZE];
int top = -1;

int push(int data) {
	if (top == SIZE - 1) { //overflow 확인
		printf("STACK is full\n");
		return -1;
	}
	//넘겨받은 데이터 push
	stack[++top] = data;
	return 0;
}

int pop(void) {
	if (top == -1) {//STACK이 비워진 상태 (underflow 상태)
		printf("STACK is empty!\n");
		return -1;
	}
	return stack[top--];
}

int main(void) {
	push(10);
	push(20);
	push(30);
	printf("%d\n", pop());	//단순화하기 위해 출력	//(용도가 다양)
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());	//underflow
	push(40);
	push(50);
	push(60);
	push(70);	//overflow
}