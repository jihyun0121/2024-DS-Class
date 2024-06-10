#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node* llink;
	char data;
	struct node* rlink;
};

struct node* createNode(char data) {
	struct node* p = (struct node*)malloc(sizeof(struct node));

	p->llink = NULL;
	p->data = data;
	p->rlink = NULL;
	return p;
}

//����Ʈ�� �Ҹ�
void deleteAll(char data) {
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->llink = NULL;
	p->data = data;
	p->rlink = NULL;
	return p;
};

//��������
void preOrder(struct node* p) {
	if (p != NULL) {
		printf("%c ", p->data);
		preOrder(p->llink);
		preOrder(p->rlink);
	}

};

//��������
void inOrder(struct node* p) {
	if (p != NULL) {
		printf("%c ", p->data);
		inOrder(p->llink);
		inOrder(p->rlink);
	}
};

//��������
void postOrder(struct node* p) {
	if (p != NULL) {
		printf("%c ", p->data);
		postOrder(p->llink);
		postOrder(p->rlink);
	}
};


int main(void) {
	struct node* root = createNode('A');
	root->llink = createNode('B');
	root->rlink = createNode('C');
	root->llink->llink = createNode('D');
	root->llink->rlink = createNode('E');
	root->rlink->rlink = createNode('F');
	root->llink->rlink->llink = createNode('G');
	root->rlink->rlink->llink = createNode('H');
	root->rlink->rlink->rlink = createNode('I');
	root->llink->rlink->llink->rlink = createNode('J');

	printf("���� ����(preOrder)  : ");
	preOrder(root); printf("\n");

	printf("���� ����(inOrder)   : ");
	inOrder(root); printf("\n");

	printf("���� ����(postOrder) : ");
	postOrder(root); printf("\n");

	deleteAll(root);

	return 0;
}