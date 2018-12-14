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

struct edge {
	int u, v, cost;
	bool operator<(const edge &other) const {
		return cost < other.cost;
	}
} E[100000];

int p[100000];

int find(int u) {
	return p[u] = (p[u] == u) ? u : find(p[u]);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].cost);
		--E[i].u;
		--E[i].v;
	}
	for (int i = 0; i < n; ++i)
		p[i] = i;
	long long MST = 0;
	sort(E, E + m);
	int cnt = 0;
	for (int i = 0; i < m; ++i) {
		int a = find(E[i].u);
		int b = find(E[i].v);
		if (a == b)
			continue;
		MST += E[i].cost;
		p[a] = b;
		++cnt;
		if (cnt == n - 1)
			break;
	}
	cout << MST << endl;
	return 0;
}

