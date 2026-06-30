//输出x1, y1, x2, y2, x3, y3
//判断前两个的线与第三个点的位置
//第三个是在他的左侧还是右侧，还是线上
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
 
using namespace std;
void solve() {
   int t;
   cin >> t;
   while (t--) {
      double x1, y1, x2, y2, x3, y3;
      cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      double res = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
      if (res == 0) cout << "TOUCH" << endl;
      else if (res > 0) cout << "LEFT" << endl;
      else cout << "RIGHT" << endl;
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
