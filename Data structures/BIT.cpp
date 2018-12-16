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

const int N = 2e5 + 2;

int n, BIT[N], a[N];

void update(int idx, int val) {
	while (idx <= n) {
		BIT[idx] += val;
		idx += idx & -idx;
	}
}
int get(int idx) {
	int sum = 0;
	while (idx > 0) {
		sum += BIT[idx];
		idx -= idx & -idx;
	}
	return sum;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		update(i, a[i]);
	}
	int q, i, j;
	cin >> q;
	while (q--) {
		cin >> i >> j;
		int res = get(j) - get(i - 1);
		cout << res << endl;
	}
	return 0;
}

