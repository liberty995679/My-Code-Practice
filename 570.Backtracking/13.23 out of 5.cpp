//是否可以通过重新排列这 5 个数
//并在它们之间依次插入运算符 +、- 或 *
//使得最终计算结果恰好等于 23。
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> arr(5);
bool found = false;
void dfs(int u, int sum) {
   if (found) return;
   if (u == 5) {
      if (sum == 23) found = true;
      return;
   }
   dfs(u + 1, sum + arr[u]);
   dfs(u + 1, sum - arr[u]);
   dfs(u + 1, sum * arr[u]);
}

void solve() {
   while (true) {
      int cnt = 0;
      arr.assign(5, 0);
      for (int i = 0; i < 5; i++) {
         cin >> arr[i];
         if (arr[i] == 0) {
            cnt++;
         }
      }
      if (cnt == 5) break;
      found = false;
      sort(arr.begin(), arr.end());
      do{
         dfs(1, arr[0]);
         if (found) break;
      } while (next_permutation(arr.begin(), arr.end()));
      if (found) cout << "Possible" << endl;
      else cout << "Impossible" << endl;

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