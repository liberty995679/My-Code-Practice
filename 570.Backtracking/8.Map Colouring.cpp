//给地图上色
//国家数量，边界数量
//国家i和国家j有边界
//输出上色地图所需的最小颜色数量
//超过4,输出 many
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
int C;
vector<vector<int>> g; 
vector<int> colors;  //每个国家的颜色

bool check(int node, int color) { //判断给node国家涂颜色是否合法
   for (int i = 0; i < g[node].size(); i++) {
      int v = g[node][i];
      if (colors[v] == color) return false;
   }
   return true;
}

bool dfs(int node, int k) { //k为颜色数
   if (node == C) return true;  //尝试k种颜色
   for (int color = 0; color < k; color++) {
      if (check(node, color)) {
         colors[node] = color;  //染色
         if (dfs(node + 1, k)) return true;
         colors[node] = -1;  //回溯
      }
   }
   return false;
}

bool cancolor(int k) {
   colors.assign(C, -1);
   return dfs(0, k);
}

void solve() {
   int t;
   cin >> t;
   while (t--) {
      int b;
      cin >> C >> b;
      if (b == 0) {
         cout << 1 << endl;
         continue;
      }
      g.assign(C, vector<int>());
      for (int i = 0; i < b; i++) {
         int u, v;
         cin >> u >> v;
         g[u].push_back(v);
         g[v].push_back(u);
      }
      bool found = false;
      for (int k = 1; k <= 4; k++) {
         if (cancolor(k)) {
            cout << k << endl;
            found = true;
            break;
         }
      }
      if (!found) {
         cout << "many" << endl;
      }
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