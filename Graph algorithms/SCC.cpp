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

const int N = 1e5 + 2;

int n, low[N], idx[N], dfs = 1, compOf[N];
bool vis[N];
vector<vector<int>> g, G;
vector<vector<int>> comp;
vector<int> S;

void DFS(int u) {
    low[u] = idx[u] = dfs++;
    S.push_back(u);
    vis[u] = true;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (idx[v] == 0)
            DFS(v);
        if (vis[v])
            low[u] = min(low[u], low[v]);
    }
    if (low[u] == idx[u]) {
        comp.push_back(vector<int>());
        while (true) {
            int v = S.back();
            comp.back().push_back(v);
            S.pop_back();
            vis[v] = false;
            if (v == u)
                break;
        }
    }
}

int main() {
    int m, a, b;
    cin >> n >> m;
    g.resize(n);
    while (m--) {
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
    }
    for (int i = 0; i < n; ++i)
        if (idx[i] == 0)
            DFS(i);
    for (int i = 0; i < comp.size(); ++i) {
        cout << comp[i].size();
        sort(comp[i].begin(), comp[i].end());
        for (int j = 0; j < comp[i].size(); ++j) {
            cout << " " << comp[i][j] + 1;
        }
        cout << "\n";
    }
    return 0;
}

