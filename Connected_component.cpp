//2019023436_������_12838
#include <iostream>
#include <set>
using namespace std;

int N; //��� ����
int M; //���� ����

int parent[1005];
set<int> s;

int Parent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = Parent(parent[x]);
}

void Union(int x, int y) {
	
	parent[Parent(x)] = Parent(y);
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= M; i++) {
		int x, y;
		cin >> x >> y;

		Union(x, y);
	}

	for (int i = 1; i <= N; i++) {
		s.insert(Parent(i));
	}

	cout << s.size();
}