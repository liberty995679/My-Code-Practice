//计算两个向量的长度
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
void solve() {
   double x1, y1, x2, y2;
   cin >> x1 >> y1 >> x2 >> y2;
   double ans = sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2));
   cout << fixed << setprecision(6) << ans << endl;
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