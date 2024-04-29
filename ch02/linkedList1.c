#include <stdio.h>
#include <stdlib.h>
int main(void) {
	struct node {
		char data;
		struct node* link;
	};
	char input = ' ';
	struct node* head, * p;
	head = (struct node*)malloc(sizeof(struct node));
	p = head;
	p->data = input;
	p->link = NULL;
	printf("데이터 입력: ");
	scanf_s("%c", &input, 1);
	getchar();
	while (input != '0') {
		p->link = (struct node*)malloc(sizeof(struct node));
		p = p->link;
		p->data = input;
		p->link = NULL;
		printf("데이터 입력");
		scanf_s("%c", &input, 1);
		getchar();
	}
	p = head->link;
	while (p != NULL) {
		printf("%c", p->data);
		if (p->link != NULL) { prinf("->"); }
		p = p->link;
	}
	printf("\n");
	return 0;
}