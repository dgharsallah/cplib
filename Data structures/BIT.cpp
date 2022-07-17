#include <bits/stdc++.h>
using namespace std;

class BIT {
public:
    BIT(vector<int> a) { 
        this->a = {0};
        this->bit.resize(2*a.size());
        for (int i = 0; i < a.size(); ++i) {
            this->a.push_back(a[i]);
        }
        for (int i = 1; i < this->a.size(); ++i)
            update(i, this->a[i]);
    }
    void update(int idx, int val) {
        while (idx <= bit.size()) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }
    int get(int idx) {
        int sm = 0;
        while(idx > 0) {
            sm += bit[idx];
            idx -= idx & -idx;
        }
        return sm;
    }
private:
    vector<int> a;
    vector<int> bit;
};

int main() {
    BIT b = BIT({1,2,3,4,5});
    vector<pair<int,int>> queries = {{1,1},{2,2},{1,2},{1,5}};
    vector<int> out = {1,2,3,15};
	for (int i = 0; i < queries.size(); ++i) {
		int l = queries[i].first;
        int r = queries[i].second;
		int res = b.get(r) - b.get(l - 1);
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
