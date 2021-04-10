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

/*
WHITE : Vertex is not processed yet. Initially, all vertices are WHITE.
GRAY: Vertex is being processed (DFS for this vertex has started, but not finished which means that all descendants (in DFS tree) 
      of this vertex are not processed yet (or this vertex is in the function call stack)
BLACK : Vertex and all its descendants are processed. While doing DFS, if an edge is encountered from current vertex to a GRAY vertex, 
        then this edge is back edge and hence there is a cycle.
*/
int n, m, e, colors[N], U = -1, V = -1; // 0 white, 1 grey, 2 black
vector<int> cycle;
vector<vector<int>> graph;

bool dfs(int u) {
    // Node and its descedants are processed, nothing to explore
    if (colors[u] == 2) {
        return false;
    }
    // This node was visited at some point but not finished. Cycle detected!
    if (colors[u] == 1) {
        e = u;
        return true;
    }
    // mark the node as visited but not completely processed
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
    // mark node as completely processed
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
