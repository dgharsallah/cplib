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

const int N = 1e6 + 7;

int n, dp[101][101];

int go(int i, int j) {
  if (i == n - 1 && j == n - 1)
    return 1;
  if (i >= n || j >= n)
    return 0;
  int &ret = dp[i][j];
  if (ret != -1) return ret;
  ret = go(i + 1, j);
  ret += go(i, j + 1);
  return ret;
}

// recursive DP solution
int sol1(int n) {
    memset(dp, -1, sizeof dp);
    return go(0, 0);
}

// iterative DP solution
int sol2(int n) {
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > 0)
                dp[i][j] += dp[i - 1][j];
            if (j > 0)
                dp[i][j] += dp[i][j - 1];
        }
    }
    return dp[n - 1][n - 1];
}

// Dp with O(n) memory
int sol3(int n) {
  int lastRow[N], curRow[N];
  memset(curRow, 0, sizeof curRow);
    memset(lastRow, 0, sizeof lastRow);
  lastRow[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        curRow[j] = lastRow[j]; // cur row is like [i] and prev row is like [i - 1]
        if (j > 0)
            curRow[j] += curRow[j - 1];
    }
    for (int j = 0; j < n; ++j) {
      lastRow[j] = curRow[j];
    }
  }
  return lastRow[n - 1];
}

int main() {
    for (int i = 1; i <= 15; ++i) {
        n = i;
        int s1 = sol1(i);
        int s2 = sol2(i);
        int s3 = sol3(i);
        cout << s1 << " " << s2 << " " << s3 << endl;
        if (s1 != s2 || s2 != s3)
            cout << "Failed at testcase " << i << endl;
    }
    // inner testcases :D
    cout << "Passed the testcases!\n";
    return 0;
}
