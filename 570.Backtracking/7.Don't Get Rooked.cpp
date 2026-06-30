//国际象棋车的位移是一行或者一列
//加上了墙壁
//计算可以在棋盘上放置的合法配置中的最大车数。
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>

#include <algorithm>

using namespace std;
vector<vector<int> > vis;
int res = 0;

bool panduan(int r, int j) {  //因为是向右和向下递归，所以只需判断左和上是否已经放了车
   for (int i = r - 1;  i >= 0 && vis[i][j] != -1 ; i--) {
      if (vis[i][j] == 1) return false;
   }
   for (int w = j - 1; w >= 0 && vis[r][w] != -1; w--) {
      if (vis[r][w] == 1) return false;
   }
   return true;
}

void dfs(int pos, int t, int sum) { //按行来有墙隔着,所以按格子来
   if (pos == t * t) {
      res = max(res, sum);
      return;
   }
   dfs(pos + 1, t, sum); //不放
   int r = pos / t;
   int c = pos % t;
   if (vis[r][c] == 0 && panduan(r, c)) {
      vis[r][c] = 1;
      dfs(pos + 1, t, sum + 1); //放
      vis[r][c] = 0;
   }
}

void solve() {
   int t;
   while (cin >> t) {
      if (t == 0) break;
      vector<string> a(t);
      vis.assign(t, vector<int>(t, 0));
      for (int i = 0; i < t; i++) {
         cin >> a[i];
         for (int j = 0; j < t; j++) {
            if (a[i][j] == 'X') vis[i][j] = -1;
         }
      }
      res = 0;
      dfs(0, t, 0);
      cout << res <<  endl;
   }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   ios::sync_with_stdio(false);
   cin.tie(0);
   solve();
   return 0;
}