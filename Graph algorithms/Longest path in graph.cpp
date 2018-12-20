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
typedef long long ll;

int n, m, a, b, longestPath, atNode;
vector<vector<int>> g;
bool vis[3001];

void dfs(int u, int length) {
    vis[u] = true;
    if (longestPath < length) {
        longestPath = length;
        atNode = u;
    }
    for (int i = 0; i < g[u].size(); ++i)
        if (!vis[g[u][i]])
            dfs(g[u][i], length + 1);
}

int main() {
    scanf("%d%d", &n, &m);
    g.resize(n);
    while (m--) {
        scanf("%d%d", &a, &b);
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    longestPath = -1;
    dfs(0, 0);
    memset(vis, false, sizeof vis);
    longestPath = -1;
    dfs(atNode, 0);
    cout << longestPath << endl;
    return 0;
}

