//2019023436_±èÇö¼ö_12838
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

void merge(int* arr, int start, int mid, int end);
void merge_sort(int* arr, int l, int r);

int main(void) {

	int N; scanf("%d", &N);

	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	merge_sort(arr, 0, N - 1);

	for (int i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}

void merge_sort(int* arr, int start, int end) {
	if (end <= start) return;

	int mid = (start + end) / 2;

	merge_sort(arr, start, mid);
	merge_sort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}

void merge(int* arr, int start, int mid, int end) {
	int* sorted = (int*)malloc(sizeof(int) * (end - start + 1));

	// start ~ mid, mid+1 ~ end
	int i = start;
	int j = mid + 1;
	int k = 0; // for sorted list

	while (i <= mid && j <= end) {
		if (arr[i] < arr[j]) {
			sorted[k++] = arr[j++];
		}
		else {
			sorted[k++] = arr[i++];
		}
	}

	if (i > mid) { //if entities of right subarray are left
		for (int a = j; a <= end; a++) {
			sorted[k++] = arr[a];
		}
	}
	if (j > end) { //if entities of left subarray are left
		for (int a = i; a <= mid; a++) {
			sorted[k++] = arr[a];
		}
	}
	
	int idx = 0;
	for (int a = start; a <= end; a++) {
		arr[a] = sorted[idx++];
	}
}