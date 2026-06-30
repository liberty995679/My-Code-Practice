//已知点a和点b的坐标，角b的度数，bc的长度
//求点c的坐标
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;
using ll = long long;

const double pi = acos(-1);

//可以将ab旋转m度到bc，这是逆时针旋转
void solve() {
   int t;
   cin >> t;
   while (t--) {
      int x1, y1, x2, y2, m, l;  //m是度数
      cin >> x1 >> y1 >> x2 >> y2 >> m >> l;
      double dx = x1 - x2;
      double dy = y1 - y2;
      double angle_ba = atan2(dy, dx);  // 向量ba的弧度 
      double theta =angle_ba + m * pi / 180.0;  //加上m的弧度
      double cx = x2 + l * cos(theta);   //x = 起点x + r × cos(θ)
      double cy = y2 + l * sin(theta);   //y = 起点y + r × sin(θ)
      cout << round(cx) << " " << round(cy) << endl; //四舍五入到最近的整数
   }
}

int main() {
// #ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
// #endif
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   solve();
   return 0;
}