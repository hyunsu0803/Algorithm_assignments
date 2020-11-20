//2019023436_±èÇö¼ö_12838
#include <iostream>
#include <climits>
using namespace std;

int N;
int p[105];
long long m[105][105];
int s[105][105];

void printMatrix(int i, int j) {
	if (i == j) {
		cout << i << " ";
		return;
	}

	cout << "( ";
	printMatrix(i, s[i][j]);
	printMatrix(s[i][j] + 1, j);
	cout << ") ";
}

int main(void) {
	cin >> N;
	for (int i = 0; i <= N; i++) {
		cin >> p[i];
	}

	for (int l = 2; l <= N; l++) {
		for (int i = 1; i <= N - l + 1; i++) {
			int j = l + i - 1;

			m[i][j] = INT_MAX;

			for (int k = i; k <= j; k++) {
				if (m[i][j] > m[i][k] + m[k + 1][j] + (long long)p[i - 1] * p[k] * p[j]) {
					m[i][j] = m[i][k] + m[k + 1][j] + (long long)p[i - 1] * p[k] * p[j];
					s[i][j] = k;
				}
			}
		}
	}

	cout << m[1][N] << "\n";
	printMatrix(1, N);
	
}