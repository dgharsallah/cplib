#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
#define ll long long
using namespace std;

int low[100000], idx[100000], dfs = 1;
bool articulations[100000];
vector<pair<int, int>> bridges;
vector<vector<int>> g;
int root, child = 0;

void DFS(int u, int p) {
	low[u] = idx[u] = dfs++;
	for (int i = 0; i < g[u].size(); ++i)
		if (idx[g[u][i]] == 0) {
			if (root == u)
				++child;
			DFS(g[u][i], u);
			low[u] = min(low[u], low[g[u][i]]);
			int v = g[u][i];
			if (low[v] >= idx[u])
				articulations[u] = true;
			if (low[v] > idx[u])
				bridges.push_back(make_pair(min(u, v), max(u, v)));
		} else if (p != g[u][i])
			low[u] = min(low[u], idx[g[u][i]]);
}

int main() {
	int n, m, u, v;
	cin >> n >> m;
	g.resize(n);
	while (m--) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	root = 0;
	DFS(root, -1);
	articulations[root] = child >= 2;
	return 0;
}

