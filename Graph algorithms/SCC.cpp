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
int n, low[100000], idx[100000], dfs = 1, compOf[100000];
bool vis[100000];
vector<vector<int>> g, G;
vector<vector<int>> comp;
vector<int> S;
void DFS(int u)
{
    low[u] = idx[u] = dfs++;
    S.push_back(u);
    vis[u] = true;
    for (int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        if (idx[v] == 0)
            DFS(v);
        if (vis[v])
            low[u] = min(low[u], low[v]);
    }
    if (low[u] == idx[u])
    {
        comp.push_back(vector<int>());
        while (true)
        {
            int v = S.back();
            comp.back().push_back(v);
            S.pop_back();
            compOf[v] = comp.size() - 1;
            vis[v] = false;
            if (v == u)
                break;
        }
    }
}
bool out[100000] = {};
int main()
{
    int m, a, b;
    cin >> n >> m;
    g.resize(n);
    while (m--)
    {
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
    }
    for (int i = 0; i < n; ++i)
        if (idx[i] == 0)
            DFS(i);
    G.resize(comp.size());
    set<pair<int, int>> visEdge;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < g[i].size(); ++j)
        {
            int u = compOf[i];
            int v = compOf[g[i][j]];
            if (u == v)
                continue;
            if (visEdge.insert(make_pair(u, v)).second)
            {
                G[u].push_back(v);
                out[u] = true;
            }
        }
    for (int i = 0; i < G.size(); ++i)
        if (out[i] == false)
        {
            cout << comp[i].size() << endl;
            sort(comp[i].begin(), comp[i].end());
            for (int j = 0; j < comp[i].size(); ++j)
            {
                if (j != 0)
                    cout << " ";
                cout << comp[i][j] + 1;
            }
        }
    return 0;
}