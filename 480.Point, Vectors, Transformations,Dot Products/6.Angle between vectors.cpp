//输入两个二维向量
//求他们的夹角
//范围是 [0, π]（弧度制）
//精度至少 10^-5
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;
using ll = long long;

void solve() {
   int x1, y1, x2, y2;
   cin >> x1 >> y1 >> x2 >> y2;  //a * b = |a||b|costheta
   int dot = x1 * x2 + y1 * y2;   // a * b / |a||b|
   double norm1 = sqrt(x1 * x1 + y1 * y1);
   double norm2 = sqrt(x2 * x2 + y2 * y2);
   double cos_theta = dot / (norm1 * norm2);
   if (cos_theta > 1) cos_theta = 1;
   else if (cos_theta < -1) cos_theta = -1;
   cout << fixed << setprecision(5) << acos(cos_theta) << endl;
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