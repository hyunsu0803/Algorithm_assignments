//2019023436_±èÇö¼ö_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

int visited[1005];
int N, M;
int graph[1005][1005];
int cycle;
stack<int> s;

void dfs(int now) {
	visited[now] = 1;
	for (int i = 1; i <= N; i++) {
		if (graph[now][i]) {
			if (visited[i] == 1) {
				cycle = 1;
				printf("0\n");
				return;
			}
			else if (visited[i] == 2) 
				continue;
			else
				dfs(i);
		}
	}
	s.push(now);
	visited[now] = 2;
}

int main(void) {
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= M; i++) {
		int x, y;
		scanf("%d%d", &x, &y);

		graph[x][y] = 1;
	}

	memset(visited, 0, sizeof(visited));

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) dfs(i);
	}

	if (cycle) return 0;

	printf("1\n");
	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}
}