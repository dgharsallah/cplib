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

struct pos {
  int r, c, cost;
};

int shortestCellPath(const vector<vector<int>>& grid, int sr, int sc, int tr, int tc) {
  int R = grid.size(), C = grid[0].size();
  vector<vector<bool>> vis(R, vector<bool>(C, 0));
  int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};
  queue<pos> q;
  q.push({sr, sc, 0});
  while(!q.empty()) {
    pos cur = q.front();
    q.pop();
    if (cur.r == tr && cur.c == tc) {
      return cur.cost;
    }
    for (int i = 0; i < 4; ++i) {
      int nxtR = cur.r + dr[i];
      int nxtC = cur.c + dc[i];
      // check validity of next position (inside grid && 1 && !vis): can only walk on ones
      if (nxtC >= 0 && nxtC < C && nxtR >= 0 && nxtR < R && grid[nxtR][nxtC] && !vis[nxtR][nxtC]) {
        q.push({nxtR, nxtC, cur.cost + 1});
        vis[nxtR][nxtC] = true;
      }
    }
  }
  return -1;
}
struct testcase {
    vector<vector<int> > grid;
    int sr, sc, tr, tc;
    int output;
};

int main() {
    testcase testcases[] = {
        testcase{
            grid:{{1, 1, 1, 1}, {0, 0, 0, 1}, {1, 1, 1, 1}},
            sr:0, sc:0,
            tr:2, tc:0,
            output: 8
        },
        testcase{
        grid: {{1, 1, 1, 1}, {0, 0, 0, 1}, {1, 0, 1, 1}},
            sr:0, sc:0,
            tr:2, tc:0,
            output: -1
        }
    };
    for (auto tc : testcases) {
        if (shortestCellPath(tc.grid, tc.sr, tc.sc, tc.tr, tc.tc) != tc.output) {
            cout << "Failed testcase\n";
        }
    }
    cout << "Passed testcases!\n";
    return 0;
}
