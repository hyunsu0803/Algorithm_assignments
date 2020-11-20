//2019023436_±èÇö¼ö_12838
#include <iostream>
#include <climits>
using namespace std;

int N; 
int p[105];

int r[105];
int s[105];

void printLen(int l) {
	if (l <= 0) return;

	cout << s[l] << " ";
	printLen(l - s[l]);
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
	}

	r[0] = 0;
	for (int i = 1; i <= N; i++) {
		r[i] = INT_MIN;
		for (int j = 1; j <= i; j++) {
			if (r[i] < p[j] + r[i - j]) {
				r[i] = p[j] + r[i - j];
				s[i] = j;
			}
		}
	}

	cout << r[N] << '\n';
	printLen(N);
}