#include <stdio.h>
#include <stdlib.h>

struct node {
	int coefficient;
	int degree;
	struct node* link;
};

struct node* makeNode(int coefficient, int degree) {
	struct node* mNode;
	mNode = (struct node*)malloc(sizeof(struct node));
	mNode->coefficient = coefficient;
	mNode->degree = degree;
	mNode->link = NULL;
	return mNode;
}

void insertNode(struct node* p, int coefficient, int degree) {
	struct node* mNode, * previous = p;

	if (coefficient == 0) return;
	mNode = makeNode(coefficient, degree);
	p = p->link;
	while (p != NULL) {
		if (p->degree > mNode->degree) {
			previous = p;
			p = p->link;
		}
		else if (p->degree < mNode->degree) {
			mNode->link = previous->link;
			previous->link = mNode;
			break;
		}
		else {
			p->coefficient += mNode->coefficient;
			if (p->coefficient == 0) {
				previous->link = p->link;
				free(p);
			}
			free(mNode);
			break;
		}
	}
	if (previous->link == NULL) previous->link = mNode;
}

struct node* addPolynomial(struct node* a, struct node* b) {
	struct node* add, * p;
	int coefficient;

	add = makeNode(0, 0);
	p = add;
	a = a->link;
	b = b->link;

	while (a && b) {
		if (a->degree > b->degree) {
			p->link = makeNode(a->coefficient, a->degree);
			p = p->link;
			a = a->link;
		}
		else if (a->degree < b->degree) {
			p->link = makeNode(b->coefficient, b->degree);
			p = p->link;
			b = b->link;
		}
		else if (a->degree == b->degree) {
			if (coefficient = a->coefficient + b->coefficient) {
				p->link = makeNode(coefficient, a->degree);
				p = p->link;
			}
			a = a->link;
			b = b->link;
		}
	}

	while (a) {
		p->link = makeNode(a->coefficient, a->degree);
		p = p->link;
		a = a->link;
	}

	while (b) {
		p->link = makeNode(b->coefficient, b->degree);
		p = p->link;
		b = b->link;
	}
	return add;
}

void Print(struct node* p) {
	p = p->link;
	printf("%dx^%d", p->coefficient, p->degree);
	p = p->link;
	while (p != NULL) {
		if (p->coefficient > 0) printf(" + %dx^%d", p->coefficient, p->degree);
		else printf(" - %dx^%d", p->coefficient, p->degree);
		p = p->link;
	}
	printf("\n");
}

void DeAllocate(struct node* p) {
	if (p != NULL) DeAllocate(p->link);
	free(p);
}

int main(void) {
	struct node* a = makeNode(0, 0);
	struct node* b = makeNode(0, 0);
	struct node* c;

	insertNode(a, 2, 4); insertNode(a, 3, 2);
	insertNode(a, 5, 0);

	insertNode(b, 1, 3); insertNode(b, 5, 2);
	insertNode(b, 6, 1); insertNode(b, 2, 0);

	printf("다항식 1: ");
	Print(a);
	printf("\n다항식 2: ");
	Print(b);

	c = addPolynomial(a, b);
	printf("\n다항식합: ");
	Print(c);

	printf("\n다항식합에 x^5과 2x^3을 추가한 결과\n");
	insertNode(c, 1, 5); insertNode(c, 2, 3);
	Print(c);

	DeAllocate(a); DeAllocate(b); DeAllocate(c);
	return 0;
}