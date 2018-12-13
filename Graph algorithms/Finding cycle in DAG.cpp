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
#include <algorithm>
#include <iomanip>
using namespace std;

const int N = 501;

int n, m, e, colors[N], U = -1, V = -1; // 0 white, 1 grey, 2 black
vector<int> cycle;
vector<vector<int>> graph;

bool dfs(int u) {
    if (colors[u] == 2) {
        return false;
    }
    if (colors[u] == 1) {
        e = u;
        return true;
    }
    colors[u] = 1;
    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (u == U && v == V) {
            continue;
        }
        if (dfs(v)) {
            if (cycle.empty() || cycle.back() != e) {
                cycle.push_back(u);
            }
            return true;
        }
    }
    colors[u] = 2;
    return false;
}

int main() {
    scanf("%d %d", &n, &m);
    graph.resize(n);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        --u, --v;
        graph[u].push_back(v);
    }
    for (int i = 0; i < n; ++i) {
        if (dfs(i)) {
            break;
        }
    }
    if (cycle.empty()) {
        puts("No cycle");
        return 0;
    } else {
        puts("Cycle found");
        for (int i = 0; i < cycle.size(); ++i) {
            cout << cycle[i] +  1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
