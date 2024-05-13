#include <stdio.h>
#define SIZE 6

//�������� ����
int stack[SIZE];
int top = -1;

int push(int data) {
	if (top == SIZE - 1) { //overflow Ȯ��
		printf("STACK is full\n");
		return -1;
	}
	//�Ѱܹ��� ������ push
	stack[++top] = data;
	return 0;
}

int pop(void) {
	if (top == -1) {//STACK�� ����� ���� (underflow ����)
		printf("STACK is empty!\n");
		return -1;
	}
	return stack[top--];
}

int main(void) {
	push(10);
	push(20);
	push(30);
	printf("%d\n", pop());	//�ܼ�ȭ�ϱ� ���� ���	//(�뵵�� �پ�)
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());	//underflow
	push(40);
	push(50);
	push(60);
	push(70);	//overflow
}