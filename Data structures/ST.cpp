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

const int N = 1e5 + 2;

int n, tree[2 * N], a[N];

void build(int node, int start, int end) {
	if (start == end) {
		tree[node] = A[start];
		return;
	}
	int mid = (start + end) / 2;
	build(2 * node, start, mid);
	build(2 * node + 1, mid + 1, end);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void update(int node, int start, int end, int idx, int val) {
	if (start == end) {
		tree[node] += val;
		return
	}
	int mid = (start + end) / 2;
	if (start <= idx and idx <= mid) {
		update(2 * node, start, mid, idx, val);
	} else {
		update(2 * node + 1, mid + 1, end, idx, val);
	}
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int query(int node, int start, int end, int l, int r) {
	if (end < l || r < start)  {
		return 0;
	}
	if (l <= start and end <= r) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	int L = query(2 * node, start, mid, l, r);
	int R = query(2 * node + 1, mid + 1, end, l, r);
	return L + R;
}
int main() {
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		build(i, 1, n);
	}
	while(q--) {
		cin >> l >> r;
		cout << query(0, 1, n, l, r);
	}
	return 0;
}
