//八皇后问题变种
//输入一个已经放好的八个皇后的位置
//输出最少移动次数，使其变成合法的八皇后布局
//某一行的皇后只能改变它所在的列
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
vector<bool> col(9, false);
vector<bool> diag1(16, false), diag2(16, false);
vector<int> arr;
vector<vector<int>> ans;
vector<int> cur(9);
void dfs(int i) {
   if (i == 9) {
      vector<int> sol(cur.begin() + 1, cur.end());
      ans.push_back(sol);
      return;
   }
      for (int r = 1; r <= 8; r++) {
         if (col[r]) continue;
         if (diag1[i + r]) continue;
         if (diag2[i - r + 8]) continue;
         col[r] = true;
         diag1[i +  r] = true;
         diag2[i - r + 8] = true;
         cur[i] = r;
         dfs(i + 1);
         col[r] = false;
         diag1[i +  r] = false;
         diag2[i - r + 8] = false;
      }
}

void solve() {
   int c = 1;
   dfs(1);
   while (true) {
      arr.clear();
      bool flag = true;
      for (int i = 0; i < 8; i++) {
         int a;
         if (!(cin >> a)) {
            flag = false;
            break;
         }
         arr.push_back(a);
      }
      if (!flag) break;
      int res = 1e9;
      for (auto& adj: ans) {
         int cnt = 0;
         for (int i = 0; i < adj.size(); i++) {
            if (arr[i] != adj[i]) cnt++;  //只要不同就算移动一次
         }
         res = min(res, cnt);
      }
      cout << "Case " << c++ << ": " << res << endl;
   }
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