//给一个二维平面的非原点
//求他的极角
//用弧度制表示，范围在[0, 2pi)
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
const double pi = acos(-1); //通过反余弦函数计算pi值 3.1415926
void solve() {
   int x, y;
   cin >> x >> y;   //反正切函数, 注意是y / x,所以是(y, x)
   double ans = atan2(y, x); //直接返回坐标对应的极角（0~2π）
   if (ans < 0) ans += 2 * pi;
   cout << ans << endl;
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