//找到所有从节点1出发的哈密顿回路
//从某个节点出发，每个节点恰好访问一次
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <sstream>
using namespace std;
vector<bool> vis;
vector<vector<int>> g;   
vector<int> path;
set<vector<int>> res;
int n;
bool dfs(int u, int cnt) {
   if (cnt == n) {
      for (int v : g[u]) {
         if (v == 1) {
            vector<int> ans = path;
            vector<int> ans1 = ans;
            reverse(ans1.begin() + 1, ans1.end());
            if (ans1 < ans)  {
               ans = ans1;
            }
            res.insert(ans);
            return true; //找到后立即停止
         }
      }
      return false;
   }
   for (int v : g[u]) {
      if (!vis[v]) {
         vis[v] = true;
         path.push_back(v);
         if (dfs(v, cnt + 1)) return true;
         vis[v] = false;
         path.pop_back();
      }
   }
   return false;
}

void solve() {
   while (cin >> n && n) {
      path.clear();
      res.clear();
      g.assign(n + 1, vector<int>());
      vis.assign(n + 1, false);
      string line;
      cin.ignore();
      while (getline(cin, line)) {
         if (line == "%") break;
         stringstream ss(line);
         int u, v;
         ss >> u >> v;
         g[u].push_back(v);
         g[v].push_back(u);
      }
      for (int i = 1; i <= n; i++) {
         sort(g[i].begin(), g[i].end());
      }
      vis[1] = true;
      path.push_back(1);
      dfs(1, 1);
      for (const auto& arr: res) {
         for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << ' ';
         }cout << 1 << endl;
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