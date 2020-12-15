//2019023436_김현수_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, pair<int, int> > pp;

int N; //노드 개수
int M; //엣지 개수
priority_queue < pp, vector<pp>, greater<pp> > input;
vector<pp> output;

int parent[1005];

int findParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = findParent(parent[x]);
}

void Union(int x, int y) {
	parent[findParent(x)] = findParent(y);
}

int main() {

	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= M; i++) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);

		input.push(make_pair(w, make_pair(x, y)));
	}

	while (!input.empty()) {
		int a = input.top().second.first;
		int b = input.top().second.second;

		if (findParent(a) == findParent(b)) {
			input.pop();		
		}
		else {
			Union(a, b);
			output.push_back(input.top());
			input.pop();
		}
	}
	
	printf("%d\n", output.size());

	for(int i = 0; i<output.size(); i++) {
		printf("%d %d %d\n", output[i].second.first, output[i].second.second, output[i].first);
	}
}
