//已知圆心 O 和半径 r，以及圆外一点 P（玫瑰位置）
//求圆上任意一点 Q，使得直线 PQ 与圆交点 R 的乘积 PQ·PR 最小。
//最小值公式就是“点 P 到圆心 O 的距离平方减去半径平方”
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;
using ll = long long;

void solve() {
   int t;
   cin >> t;
   while (t--) {
      ll x1, y1, r, x2, y2;
      cin >> x1 >> y1 >> r >> x2 >> y2;
      ll dx = x2 - x1;
      ll dy = y2 - y1;
      ll dis = dx * dx + dy * dy;
      ll ans = dis - r * r;
      cout << ans << endl;
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