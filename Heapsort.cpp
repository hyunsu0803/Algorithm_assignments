//2019023436_김현수_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct HeapStruct {
	int capacity;
	int size;
	int* Elements;
};
typedef struct HeapStruct* Heap;

Heap makeNode(int capacity);
void Insert(int x, Heap h);
int Find(int x, Heap h);
void Print(Heap h);
int Pop(Heap h);

int main() {

	int capacity, k;
	fscanf(stdin, "%d%d", &capacity, &k);

	Heap h = makeNode(capacity);

	int element;
	while (capacity--) {
		scanf("%d", &element);
		Insert(element, h);
	}
	
	//Print(h);

	while (k--) {
		printf("%d ", Pop(h));
	}
	printf("\n");

	for (int i = 1; i <= h->size; i++) {
		printf("%d ", h->Elements[i]);
	}

	return 0;
}
Heap makeNode(int capacity) {
	Heap h = (Heap)malloc(sizeof(struct HeapStruct));
	h->capacity = capacity;
	h->Elements = (int*)malloc(sizeof(int) * (capacity + 1));
	h->size = 0;
	return h;
}
void Insert(int x, Heap h) {
	if (h->size == h->capacity)
		fprintf(stdout, "heap is full\n");
//	else if (Find(x, h))
	//	fprintf(stdout, "%d is already in the heap\n", x);
	else {
		int i;
		h->size++; //일단 여기에 x를 넣어두고
		// i는 x의 인덱스
		// i가 root노드가 아니고, i가 부모보다 크면 자리바꾸기
		for (i = h->size; i / 2 > 0 && h->Elements[i / 2] < x; i /= 2) {
			h->Elements[i] = h->Elements[i / 2];
		}
		h->Elements[i] = x;
	}
}
int Find(int x, Heap h) {
	for (int i = 1; i <= h->size; i++) {
		if (h->Elements[i] == x) {
			return 1;
		}
	}
	return 0;
}
void Print(Heap h) {
	for (int i = 1; i <= h->size; i++) {
		fprintf(stdout, "%d ", h->Elements[i]);
	}
	fprintf(stdout, "\n");
}
int Pop(Heap h) {

	int ret = h->Elements[1];

	int key = h->Elements[h->size];
	h->Elements[1] = key;
	h->size--;

	int i = 1;
	while ((i * 2 <= h->size && h->Elements[i * 2] > key) || (i * 2 + 1 <= h->size && h->Elements[i * 2 + 1] > key))
	{
		if (i * 2 + 1 <= h->size && h->Elements[i * 2] < h->Elements[i * 2 + 1]) {
			
			h->Elements[i] = h->Elements[i * 2 + 1];
			i = i * 2 + 1;
		}
		else {
			h->Elements[i] = h->Elements[i * 2];
			i = i * 2;
		}
	}
	h->Elements[i] = key;

	return ret;
}