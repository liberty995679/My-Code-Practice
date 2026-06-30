//输入鼠标的起始位置和结束位置
//唱片转速：33⅓ RPM（每分钟旋转33.333...圈），顺时针方向
//计算鼠标拖动时，唱片旋转角度的变化
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;
using ll = long long;

const double pi = acos(-1);
const double rpm = 100.0 / 3.0;  //将角度差转换为一圈的比例，再转换为相应的时间，单位是秒。
void solve() {   //唱片的中心在(d/2, d/2)
   int d;
   cin >> d; //黑胶唱片的直径
   int x1, y1, x2, y2;
   cin >> x1 >> y1 >> x2 >> y2;
   double round_xy = d / 2.0;
   // 检查起点和终点是否在圆内
   double dist1 = sqrt((x1 - round_xy) * (x1 - round_xy) + (y1 - round_xy) * (y1 - round_xy));
   double dist2 = sqrt((x2 - round_xy) * (x2 - round_xy) + (y2 - round_xy) * (y2 - round_xy));
   if (dist1 > d / 2 || dist2 > d / 2) {
       cout << 0 << endl;
       return;
   }
   double angle_oa = atan2(y1 - round_xy, x1 - round_xy);  //唱片顺时针转 -> 倒退(负)
   double angle_ob = atan2(y2 - round_xy, x2 - round_xy);  //唱片逆时针转 -> 快进(正)
   double diff = angle_ob - angle_oa;
   while (diff > pi) diff -= 2 * pi;
   while (diff < -pi) diff += 2 * pi;
   double ans = (-diff / (2 * pi)) / rpm * 60; //除以转速得到每转一圈需要的时间，然后乘以60秒
   cout << fixed << setprecision(6);  //两者方向相反
   cout << ans << endl;  //→ 你的手逆时针移动了 → 但方向盘是顺时针转动的！
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