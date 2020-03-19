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

const int N = 2e5 + 7;
const ll MOD = 998244353;

int main() {
    string s = "helleo";
    int n = s.size(), maxLen = 1, L = 0, R;
    for (int i = 1; i < n; ++i) {
        int l = i - 1, r = i;
        while(l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                L = l;
                R = r;
            }
            --l, r++;
        }
        l = i - 1, r = i + 1;
        while(l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                L = l;
                R = r;
            }
            --l, r++;
        }
    }
    cout << s.substr(L, maxLen) << endl;
    return 0;
}
 
