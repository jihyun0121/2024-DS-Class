#include <stdio.h>
#define SIZE 8

int queue[SIZE];
int rear = -1, front = 0;

typedef enum { false, true } bool;

void add(int index) {
	queue[++rear] = index;
}

int delet(void) {
	if (rear < front) return -1;
	return queue[front++];
}

void BreadthFirstSearch(char V[], bool G[][SIZE]) {
	int i, j;
	char startVertex;
	bool searchOK[SIZE] = { false };

	printf("출발정점 : "); scanf_s("%c", &startVertex, 1);
	for (i = 0; i < SIZE; i++) if (V[i] == startVertex) break;

	printf("\n깊이 우선 탐색 : %c", startVertex);	//V[i]도 사용 가능
	searchOK[i] = true;

	do {
		for (j = 0; j < SIZE; j++) {
			if (G[i][j] == 1 && searchOK[j] == false) {
				printf(" -> %c", V[j]);
				add(j);
				searchOK[j] = true;
			}
		}
		i = delete();
	} while (i >= 0);
}

int main(void) {
	char V[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	bool G[SIZE][SIZE] = { {0, 1, 1, 0, 0, 0, 0, 0},
							{1, 0, 0, 1, 1, 0, 0, 0},
							{1, 0, 0, 0, 0, 1, 1, 0},
							{0, 1, 0, 0, 0, 0, 0, 1},
							{0, 1, 0, 0, 0, 0, 0, 1},
							{0, 0, 1, 0, 0, 0, 0, 1},
							{0, 0, 1, 0, 0, 0, 0, 1},
							{0, 0, 0, 1, 1, 1, 1, 0} };

	BreadthFirstSearch(V, G);

	return 0;
}