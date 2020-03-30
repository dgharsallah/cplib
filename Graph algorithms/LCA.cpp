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

const int N = 2e5 + 7;

int n, m, l, timer;
vector<int> tin, tout, d;
vector<vector<int>> g, up;

void dfs(int v, int p, int depth) {
    tin[v] = ++timer;
    up[v][0] = p;
    d[v] = depth;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (int u : g[v]) {
        if (u != p)
            dfs(u, v, depth + 1);
    }
    tout[v] = ++timer;
}

bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (isAncestor(u, v))
        return u;
    if (isAncestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!isAncestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int main() {
    scanf("%d%d", &n, &m);
    g.resize(n);
    tin.resize(n);
    d.resize(n);
    tout.resize(n);
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        --u, --v;
        g[u].push_back(v);
        g[u].push_back(u);
    }
    timer = 0;
    dfs(0, 0, 0);
    while(m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("LCA(%d, %d):%d\n", u, v, lca(u - 1, v - 1) + 1);
    }
    return 0;
}
/* 
Example input:
10 6
1 2
1 3
1 4
2 5
2 6
3 7
7 8
7 9
9 10
4 5
5 6
8 9
8 10
8 9
2 1
Output:
LCA(4, 5):1
LCA(5, 6):2
LCA(8, 9):7
LCA(8, 10):7
LCA(8, 9):7
LCA(2, 1):1
*/
