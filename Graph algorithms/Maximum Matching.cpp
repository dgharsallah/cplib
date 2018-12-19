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
using namespace std;

int n, m, e;
vector<vector<int>> g;
bool vis[1000];
int match[1000];

bool findPath(int u) {
	vis[u] = true;
	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if (match[v] == -1 || !vis[match[v]] && findPath(match[v])) {
			match[v] = u;
			return true;
		}
	}
	return false;
}
int maxMatching() {
	memset(match, -1, sizeof(match));
	int res = 0;
	for (int i = 0; i < n; ++i) {
		memset(vis, 0, sizeof(vis));
		if (findPath(i))
			++res;
	}
	return res;
}
int main() {
	int a, b, e;
	scanf("%d%d", &n, &e);
	g.resize(n);
	while (e--) {
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a].push_back(b);
	}
	cout << maxMatching() << endl;
	return 0;
}
