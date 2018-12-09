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

int in[10000]; // in degrees
vector<vector<int>> graph;

int main() {
	int n, m;
	cin >> n >> m;
	graph.resize(n);
	int a, b;
	while (m--) {
		cin >> a >> b;
		graph[a].push_back(b);
		++in[b];
	}
	queue<int> q;
	for (int i = 0; i < n; ++i)
		if (in[i] == 0)
			q.push(i);
	vector<int> ans;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		ans.push_back(u);
		for (int i = 0; i < graph[u].size(); ++i) {
			--in[graph[u][i]];
			if (in[graph[u][i]] == 0)
				q.push(graph[u][i]);
		}
	}
	if (ans.size() != n) {
		printf("Cycle!\n");
	} else {
		for (int i = 0; i < ans.size(); ++i)
			printf("%s%d", i ? " " : "", ans[i]);
	}
	return 0;
}
