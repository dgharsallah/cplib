#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    int n;
    SegmentTree(vector<int> a) {
        n = a.size();
        A = a;
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = A[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] += val;
            return;
        }
        int mid = (start + end) / 2;
        if (start <= idx and idx <= mid) {
            update(2 * node + 1, start, mid, idx, val);
        } else {
            update(2 * node + 2, mid + 1, end, idx, val);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    int query(int node, int start, int end, int l, int r) {
        if (end < l || r < start)  {
            return 0;
        }
        if (l <= start and end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int L = query(2 * node + 1, start, mid, l, r);
        int R = query(2 * node + 2, mid + 1, end, l, r);
        return L + R;
    }
private:
    vector<int> A, tree;
};

int main() {
	SegmentTree st = SegmentTree({1,2,3,4,5});
	vector<pair<int,int>> queries = {{1,1},{2,2},{1,2},{1,5}};
    vector<int> out = {1,2,3,15};
	for (int i = 0; i < queries.size(); ++i) {
		int l = queries[i].first;
        int r = queries[i].second;
		int res = st.query(0, 0, st.n-1, l-1, r-1);
		if (res != out[i]) {
            cout << "FAILED at testcase " << i+1 << "\n";
            cout << "Expected " << out[i] << "\n";
            cout << "Found " << res << "\n";
            return 0;
        }
	}
    cout << "PASSED!\n";
	return 0;
}
