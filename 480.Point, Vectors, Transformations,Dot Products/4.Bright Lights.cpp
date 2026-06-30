//判断是否有柱子的激光被他前面的柱子挡住
//如果有，输出xy坐标
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
//这个提交代码是标准c++11
//手写gcd

int gcd(int a, int b) {
   return b == 0 ? a : gcd(b, a % b);
}

struct pole{
   int x, y, z;
   ll dis;
};
int casenum = 1;
void solve() {
   int n;
   while (cin >> n) {
      int t = n;
      if (n == 0) return;
      map<pair<int, int>, vector<pole>> mp;
      while (t--) {
         int x, y, z;
         cin >> x >> y >> z;
         int g = gcd(abs(x), abs(y));
         int dx =x / g;   //根据方向标识分类
         int dy = y / g;
         mp[{dx, dy}].push_back({x, y, z, 1LL * x * x + 1LL * y * y});
      }
      vector<pair<int,int>> ans;
      for (auto &t: mp) {
         auto &vec = t.second; //引用
         sort(vec.begin(), vec.end(), [](pole &a, pole &b) {
            return a.dis < b.dis;  //排序，距离原点的距离,从近到远
         });
         int mxheight = -1;
         for (auto &i: vec) {
            if (i.z <= mxheight) {
               ans.push_back({i.x, i.y});
            } else {
               mxheight = i.z;
            }
         }
      }
      cout << "Data set " << casenum++ << ":" << endl;
      if (ans.size() == 0) {
         cout << "All the lights are visible." << endl;
      } else {
         sort(ans.begin(), ans.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
         });
         cout << "Some lights are not visible:" << endl;
         for (int i =0; i < ans.size(); i++) {
            cout << "x = " << ans[i].first << ", y = " << ans[i].second;
            if (i == ans.size() - 1) {
               cout << ".\n";
            } else {
               cout << ";\n";
            }
         }
      }
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