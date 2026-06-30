//找出所有从节点 1 出发、长度恰好为 n 的行走
//输入节点的数量以及路径的长度
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> g;
vector<vector<int>> ans;
vector<int> arr;
vector<bool> vis;
bool found = false;
int m, n;
void dfs(int u, int cnt) { //从u节点出发，cnt长度
   arr.push_back(u);
   vis[u] = true;
   if (cnt == n) {
      ans.push_back(arr);
      arr.pop_back();
      vis[u] = false;
      return;
   }
   for (int v: g[u]) {
      if (!vis[v]) dfs(v, cnt + 1);
   }
   arr.pop_back();
   vis[u] = false;
}

void solve() {
   bool flag = true;
   while (cin >> m) {
      if (m == -9999) {
         continue;  // 跳过分隔符,继续读下一组
      }
      if (!flag) cout << endl;
      flag = false;
      cin >> n;
      arr.clear(); ans.clear();
      g.assign(m, vector<int>());
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            if (x == 1) g[i].push_back(j);
         }
      }
      vis.assign(m, false);
      dfs(0, 0);
      if (ans.size() > 0) {
         for (int i = 0; i < ans.size(); i++) {
            cout << '(';
            for (int j = 0; j < ans[i].size(); j++) {
               if (j > 0) cout << ',';
               cout << ans[i][j] + 1;
            }
            cout << ')' << endl;
         }
      } else {
         cout << "no walk of length "<< n << endl;
      }
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