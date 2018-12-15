#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <sstream>
#include <memory.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <functional>
#include <algorithm>
#define ll long long
using namespace std;

const long long oo = 2e17;
const int N = 1e5 + 2;

int n, m, k, p[N];
vector<pair<long long, int>> graph[N];
long long dist[N];
vector<int> path;

void dijkstra(int source) {
    fill_n(dist, n + 1, oo);
    dist[source] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
    greater<pair<long long, int>>> heap;
    heap.push(make_pair(0, source));
    while (!heap.empty()) {
        int node = heap.top().second;
        long long cost = heap.top().first;
        heap.pop();
        if (cost > dist[node]) {
            continue;
        }
        for (int i = 0; i < (int) graph[node].size(); ++i) {
            int toNode = graph[node][i].second;
            long long supCost = graph[node][i].first;
            long long totalCost = supCost + cost;
            if (totalCost < dist[toNode]) {
                dist[toNode] = totalCost;
                heap.push(make_pair(totalCost, toNode));
                p[toNode] = node;
            }
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(cost, to));
        graph[to].push_back(make_pair(cost, from));
    }
    dijkstra(1);
    if (dist[n] == oo)
        cout << "-1" << endl;
    else {
        int now = n;
        while (now != 1) {
            path.push_back(now);
            now = p[now];
        }
        path.push_back(1);
        for (int i = path.size() - 1; i > 0; --i)
            cout << path[i] << " ";
        cout << n << endl;
    }
    return 0;
}

