//八皇后问题变种
//只能在.放皇后
//请问有几种方法
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
vector<string> g(8);
vector<bool> col(8, false);
vector<bool> diag1(15, false), diag2(15, false);
vector<int> arr;
vector<vector<int>> ans;
vector<int> cur(8);
void dfs(int i) {
   if (i == 8) {
      vector<int> sol(cur.begin(), cur.end());
      ans.push_back(sol);
      return;
   }
      for (int r = 0; r <= 7; r++) {
         if (col[r]) continue;
         if (diag1[i + r]) continue;
         if (diag2[i - r + 7]) continue;
         if (g[i][r] == '*') continue;
         col[r] = true;
         diag1[i +  r] = true;
         diag2[i - r + 7] = true;
         cur[i] = r;
         dfs(i + 1);
         col[r] = false;
         diag1[i +  r] = false;
         diag2[i - r + 7] = false;
      }
}
void solve() {
   for (int i = 0; i < 8; i++) {
      cin >> g[i];
   }
   dfs(0);
   int res = ans.size();
   cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   solve();
   return 0;
}