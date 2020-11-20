// 2019023436_±èÇö¼ö_12838
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

int main(void) {

	int N; scanf("%d", &N);

	int* keys = (int*)malloc(N * sizeof(int));

	for (int i = 0; i < N; i++) {
		scanf("%d", &keys[i]);
	}

	for (int i = 1; i < N; i++) {
		int key = keys[i];

		int j = i - 1;
		while (j >= 0 && keys[j] < key) {
			keys[j + 1] = keys[j];
			j--;
		}
		keys[j + 1] = key;
	}

	for (int i = 0; i < N; i++) {
		printf("%d\n", keys[i]);
	}

	return 0;
}