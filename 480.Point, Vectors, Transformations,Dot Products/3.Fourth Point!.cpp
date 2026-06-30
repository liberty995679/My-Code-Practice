//补平行四边形的第四条边
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
void solve() {
   double x1, y1, x2, y2, x3, y3, x4, y4;
   while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
      double ax, ay, bx, by, cx, cy, dx, dy;
      if (x1 == x3 && y1 == y3) {
         cx = x1; cy = y1;
         ax = x2; ay = y2; bx = x4; by = y4;
         dx = ax + bx - cx;
         dy = ay + by - cy;
      } else if (x1 == x4 && y1 == y4) {
         cx = x1; cy = y1;
         ax = x2; ay = y2; bx = x3; by = y3;
         dx = ax + bx - cx;
         dy = ay + by - cy;
      } else if (x2 == x3 && y2 == y3) {
         cx = x2; cy = y2;
         ax = x1; ay = y1; bx = x4; by = y4;
         dx = ax + bx - cx;
         dy = ay + by - cy;
      } else if (x2 == x4 && y2 == y4) {
         cx = x2; cy = y2;
         ax = x1; ay = y1; bx = x3; by = y3;
         dx = ax + bx - cx;
         dy = ay + by - cy;
      }
      cout << fixed << setprecision(3);
      cout << dx << ' ' << dy << endl;
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