//2019023436_±èÇö¼ö_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int start, int mid, int end);
void merge_sort(int* arr, int l, int r);
int lower_bound(int* arr, int N, int key);
int upper_bound(int* arr, int N, int key);
int main(void) {
	int N;
	int M;
	int K;

	scanf("%d%d%d", &N, &M, &K);

	int* arr = (int*)malloc(N * sizeof(int));

	int** range = (int**)malloc(2 * sizeof(int*));
	range[0] = (int*)malloc(K * sizeof(int));
	range[1] = (int*)malloc(K * sizeof(int));

	for (int i = 0; i < K; i++) {
		scanf("%d%d", &range[0][i], &range[1][i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	merge_sort(arr, 0, N - 1);

//	for (int i = 0; i < N; i++) 
//		printf("%d ", arr[i]);
//	printf("\n\n");
	for (int i = 0; i < K; i++) {
		int start = lower_bound(arr, N, range[0][i]);
		int end = upper_bound(arr, N, range[1][i]);
		int ans = 0;
		if (start == N) ans = 0;
		else ans = end - start;

		printf("%d\n", ans);
	}
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
			sorted[k++] = arr[i++];
		}
		else {
			sorted[k++] = arr[j++];
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

int lower_bound(int* arr, int N, int key) {
	int left = 0;
	int right = N - 1;

	int ans = N;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (key <= arr[mid]) {
			right = mid - 1;
			ans = mid;
		}
		else if (key > arr[mid]) {
			left = mid + 1;
		}
	}

	return ans;
}

int upper_bound(int* arr, int N, int key) {
	int left = 0;
	int right = N - 1;

	int ans = N;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (key < arr[mid]) {
			right = mid - 1;
			ans = mid;
		}
		else if (key >= arr[mid]) {
			left = mid + 1;
		}
	}

	return ans;
}