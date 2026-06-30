//n个坐标输入
//根据极角逆时针排序
//从-pi 到 0 输出
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;
using ll = long long;
using ld = long double;
const ld eps = 1e-9;
bool nearly(ld a,ld b) {
   return fabs(a - b) < eps;  //绝对误差，如果两个数差值非常小，认为相等
}

int panduan(int x, int y) {
   if (x == 0 && y == 0) return 0;  //原点处理
   else if (y < 0 || (y == 0 && x > 0)) return -1; //位于负半平面
   return 1;
}

void solve() {
   int n;
   cin >> n;
   vector<pair<int, int>> arr(n);
   for (int i = 0; i < n; i++) {
      cin >> arr[i].first >> arr[i].second;
   }
   sort(arr.begin(), arr.end(), [](const pair<int,int> &a, const pair<int,int> &b){
      int x1 = a.first; int y1 = a.second;
      int x2 = b.first; int y2 = b.second;
      int q1 = panduan(x1, y1);
      int q2 = panduan(x2, y2);
      if (q1 != q2) return q1 < q2;
      ll sum = (ll)x1 * y2 - (ll)x2 * y1;  //叉积
      return sum > 0;
   });
   for (int i = 0; i < n;  i++) {
      cout << arr[i].first << ' ' << arr[i].second << endl;
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