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
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#define ll long long
using namespace std;

int main() {
	vector<int> elems = {2, 1, 5};
    vector<int> res(elems.size(), 0);
    stack<int> st;
    for (int i = 0; i < elems.size(); ++i) {
        while (!st.empty() && elems[st.top()] < elems[i]) {
            res[st.top()] = elems[i];
            st.pop();
        }
        st.push(i);
    }
    for (auto e : res)
        cout << e << " ";
    cout << endl;
	return 0;
}
