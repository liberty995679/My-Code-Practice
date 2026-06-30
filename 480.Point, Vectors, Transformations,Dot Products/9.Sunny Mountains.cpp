//山脉阴影问题
//光线是水平的
//计算所有被阳光照射的部分
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;
using ll = long long;

struct val {
   int x,y;
};

double calculate(int x1, int y1, int x2, int y2) {
   double dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
   return dis;
}

void solve() {
   int t;
   cin >> t;
   while (t--) {
      int n;
      cin >> n;
      vector<val> arr(n);
      for (int i =0; i < n; i++) {
         cin >> arr[i].x >> arr[i].y;
      }
      sort(arr.begin(), arr.end(), [](const val&a, const val&b) {
         return a.x > b.x;
      });
      int max_y = 0;
      int pre_x = 0;
      int pre_y = 0;
      double res = 0;   //记录结果
      for (int i = 0; i < n; i++) {
         if (i == 0) {
            continue;
         }
         if (i > 0) {
            pre_x = arr[i - 1].x;
            pre_y = arr[i - 1].y;
         }
         int dx = arr[i].x;
         int dy = arr[i].y;
         if (dy > max_y) {    //高度比最高点高
            double dis = calculate(dx, dy, pre_x, pre_y);
            double ans = dis * (dy - max_y) / (dy - pre_y);
            res += ans;
            max_y = dy;
         }
      }
      cout << fixed << setprecision(2);
      cout << res << endl;
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