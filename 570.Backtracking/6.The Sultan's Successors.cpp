//八皇后问题
//求最大权值总和
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
using ll = long long;
vector<vector<int>> board(8, vector<int>(8, 0));     // 棋盘权值
vector<bool> col(8, false);         // 列是否被占
vector<bool> diag1(15, false);      // 主对角线：row - col + 7，范围 [-7,7] → [0,14]
vector<bool> diag2(15, false);      // 副对角线：row + col，范围 [0,14]
int ans = 0;   //当前用例最大值

void dfs(int row, int sum) { //在第row行放皇后
   if (row == 8) {
      ans = max(ans, sum);
      return;
   }
   for (int i = 0; i < 8; i++) {  //枚举列
      if (col[i]) continue;
      if (diag1[row - i + 7]) continue;
      if (diag2[row + i]) continue;
      col[i] = true;  //尝试放皇后
      diag1[row - i + 7] = true;
      diag2[row + i] = true; 
      dfs(row + 1, sum + board[row][i]);
      col[i] = false;
      diag1[row - i + 7] = false;
      diag2[row + i] = false;
   }
}
int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int t;
   cin >> t;
   while (t--) {
      ans = 0;
      board.assign(8, vector<int>(8, 0));
      col.assign(8, false);
      diag1.assign(15, false);
      diag2.assign(15, false);
      for (int i = 0; i < 8; i++) {
         for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
         }
      }
      dfs(0, 0);
      cout << setw(5) << ans << endl;
   }
   return 0;   
}