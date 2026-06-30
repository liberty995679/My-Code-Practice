//把 1,2,…n 排成一个环，使得相邻两个整数之和均为素数。
//输出时，从整数 1 开始逆时针排列
//多组数据，读入到 EOF 结束。
//第 i 组数据输出前加上一行 Case i:
//相邻两组输出中间加上一个空行（但是最后一组的末尾不要加！）
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
vector<vector<int>> res;
vector<int> path; //当前路径
vector<bool> vis;
int N;
bool is_prime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    int num = sqrt(n);    //sqrt指的是平方根
    for (int i = 2; i <= num; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void dfs(int cnt) {  //1到n
   if (cnt == N && is_prime(path[cnt - 1] + 1)) { //最后一个数加一是素数
      for (int i = 0; i < N; i++) {
         if (i > 0) cout << ' ';
         cout << path[i];
      }
      cout << endl;
      return;
   }
   for (int i = 2; i <= N; i++) {
      if (!vis[i] && is_prime(path[cnt - 1] + i)) {
         vis[i] = true;
         path.push_back(i);
         dfs(cnt + 1);
         path.pop_back();
         vis[i] = false;
      }
   }
}


void solve() {
   int k = 1;
   bool first = true;
   while (cin >> N) {
      if (!first) cout << endl;
      first = false;
      cout << "Case " << k++ << ":"<< endl;
      path.clear();
      vis.assign(N + 1, false);
      path.push_back(1);
      vis[1] = true;
      dfs(1);
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