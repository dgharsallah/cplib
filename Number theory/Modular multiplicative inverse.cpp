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
#include <unordered_map>
#include <unordered_set>
#define ll long long
using namespace std;

const ll MOD = 998244353;
const int N = 2e5 + 7;

ll fact[N];

ll add(ll x, ll y) {
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

ll mul(ll x, ll y) {
    return (x * 1ll * y) % MOD;
}

ll binpow(ll x, ll y) {
    ll z = 1;
    while (y) {
        if (y & 1)
            z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

ll inv(ll x) {
    return binpow(x, MOD - 2);
}

ll divide(ll x, ll y) {
    return mul(x, inv(y));
}

void precalc() {
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
}

ll nCk(ll n, ll k) {
    return divide(fact[n], mul(fact[k], fact[n - k]));
}

void solve() {
    precalc();
    ll n, k;
    cin >> n >> k;
    if (n == 2) {
        cout << 0 << endl;
        return;
    }
    cout << nCk(n, k) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)
        solve();
    return 0;
}
