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
#define ll long long
using namespace std;

const int A = 26;

struct node {
    vector<int> adj;
    bool end;
    node() {
        adj.resize(A, -1);
        end = false;
    }
};

struct Trie {
    vector<node> v;
    Trie() {
        v.push_back(node());
    }
    void insert(char *s) {
        int cur = 0;
        for (int i = 0; s[i]; ++i) {
            if (v[cur].adj[s[i] - 'a'] == -1) {
                v.push_back(node());
                v[cur].adj[s[i] - 'a'] = v.size() - 1;
            }
            cur = v[cur].adj[s[i] - 'a'];
        }
        v[cur].end = true;
    }
    bool find(char *s) {
        int cur = 0;
        for (int i = 0; s[i]; ++i) {
            if (v[cur].adj[s[i] - 'a'] == -1)
                return false;
            cur = v[cur].adj[s[i] - 'a'];
        }
        return v[cur].end;
    }
    string str;
    void print(int u) {
        if (v[u].end)
            puts(str.c_str());
        for (int i = 0; i < A; ++i)
            if (v[u].adj[i] != -1) {
                str += char(i + 'a');
                print(v[u].adj[i]);
                str.resize(str.size() - 1);
            }
    }
};

int main() {
    Trie t1;
    char s[100];
    while (cin >> s) {
        t1.insert(s);
    }
    t1.print(0);
    return 0;
}


