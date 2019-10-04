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
struct node {
	int m0, m1, m2;
	node() {
		m0 = m1 = m2 = 0;
	}
};
int n, v[100001], lazy[400001];
node seg[400001];
int l, r;
inline void fix(int n, bool leaf) {
	if (lazy[n]) {
		lazy[n] %= 3;
		for (int it = 0; it < lazy[n]; ++it) {
			int temp = seg[n].m2;
			seg[n].m2 = seg[n].m1;
			seg[n].m1 = seg[n].m0;
			seg[n].m0 = temp;
		}
		if (!leaf) {
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}
void merge(node &res, node &l, node &r) {
	res.m0 = l.m0 + r.m0;
	res.m1 = l.m1 + r.m1;
	res.m2 = l.m2 + r.m2;
}
void update(int n, int s, int e) {
	fix(n, s == e);
	if (s > r || e < l)
		return;
	if (s >= l && e <= r) {
		lazy[n] = 1;
		fix(n, s == e);
		return;
	}
	update(n * 2, s, (s + e) / 2);
	update(n * 2 + 1, (s + e) / 2 + 1, e);
	merge(seg[n], seg[n * 2], seg[n * 2 + 1]);
}
node get(int n, int s, int e) {
	if (s > r || e < l)
		return node();
	if (s >= l && e <= r)
		return seg[n];
	node left = get(n * 2, s, (s + e) / 2);
	node right = get(n * 2 + 1, (s + e) / 2 + 1, e);
	node ret;
	merge(ret, left, right);
	return ret;
}
int main() {
	freopen("src.txt", "r", stdin);
	return 0;
}
