//2019023436_김현수_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

void merge(int* arr, int start, int mid, int end);
void merge_sort(int* arr, int l, int r);
int binary_search(int* arr, int N, int key);


int main(void) {

	int N, M;
	scanf("%d%d", &N, &M);
	int* A = new int[N];
	int* B = new int[M];

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &B[i]);
	}

	merge_sort(A, 0, N - 1);
	merge_sort(B, 0, M - 1);

	int ans = 0;
	if (N <= M) { //B에서 A를 찾아본다
		for (int i = 0; i < N; i++) {
			if (binary_search(B, M, A[i])) ans++;
		}
	}
	else {
		for (int i = 0; i < M; i++) {
			if (binary_search(A, N, B[i])) ans++;
		}
	}

	printf("%d", ans);
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

int binary_search(int* arr, int N, int key) {
	int left = 0;
	int right = N - 1;

	int ans = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (key < arr[mid]) {
			right = mid - 1;
		}
		else if (key > arr[mid]) {
			left = mid + 1;
		}
		else if (key == arr[mid]) {
			return ans = 1;
		}
	}

	return ans;
}