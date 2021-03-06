/*
  dfs on every connected component and every person take one node from the edge , if there is a cycle with odd
  number of edges the answer is -1
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int head[N], from[N * 2], nxt[N * 2], to[N * 2], no = 0;
int be[N];
bool vis[N];
void addedge(int a, int b) {
	nxt[no] = head[a];
	to[no] = b;
	from[no] = a;
	head[a] = no++;
}

vector<int> ans[4];

void dfs(int idx, int p) {
	if (vis[idx])
		return;
	vis[idx] = 1;
	be[idx] = p + 1;
	for (int i = head[idx]; ~i; i = nxt[i]) {
		dfs(to[i], !p);
	}
}

int main() {
	memset(head, -1, sizeof head);
	int n, m;
	scanf("%d %d", &n, &m);
	int x, y;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		addedge(x, y);
		addedge(y, x);
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i])
			dfs(i, 1);
	}

	for (int i = 0; i < no; ++i) {
		if (be[from[i]] == be[to[i]]) {
			puts("-1");
			return 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		ans[be[i]].push_back(i);
	}
	for (int i = 1; i <= 2; ++i) {
		printf("%d\n", ans[i].size());
		for (auto x : ans[i])
			printf("%d ", x);
		puts("");
	}
}
