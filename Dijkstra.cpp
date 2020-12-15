//2019023436_김현수_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;

int dist[5005];
int N, M;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pp;

vector<pii> edge[5005];
priority_queue<pii, vector<pii>, greater<pii> > pq;

void dijkstra(int start) {
	for (int i = 0; i < edge[start].size(); i++) {
		int next = edge[start][i].first;
		int weight = edge[start][i].second;

		pq.push(make_pair(weight, next));
	}

	while (!pq.empty()) {
		int now = pq.top().second;
		int nowweight = pq.top().first;
		pq.pop();
		
		//already distance fixed
		if (dist[now] != INT_MAX)
			continue;

		dist[now] = nowweight;

		//now의 fix되지 않은 주변 노드를 pq에 넣는다
		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i].first;
			int nextW = edge[now][i].second;

			if (dist[next] == INT_MAX) {
				pq.push(make_pair(nowweight + nextW, next));
			}
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= M; i++) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		edge[x].push_back(make_pair(y, w));
	}

	for (int i = 1; i <= N; i++) {
		dist[i] = INT_MAX;
	}
	dist[1] = 0;

	dijkstra(1);

	int Max = 0;
	for (int i = 2; i <= N; i++) {
		if (dist[i] != INT_MAX) {
			if (Max < dist[i]) {
				Max = dist[i];
			}
		}
	}

	printf("%d\n", Max);
}