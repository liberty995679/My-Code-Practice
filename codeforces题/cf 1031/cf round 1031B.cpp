//屋顶是一个大小为 w×h的矩形，其左下角位于平面上的点 (0,0)
//你的任务是用尺寸为 a×b的相同屋面瓦完全覆盖这个屋顶
//屋面瓦不能旋转（即使是旋转 90∘也不允许）
//屋面瓦之间不能重叠（但可以在边缘接触）
//屋面瓦可以延伸到矩形屋顶的边界之外
//团队的一名新手已经放置了两块这样的屋面瓦在屋顶上，这两块瓦互不重叠，并且每块都部分覆盖了屋顶
//你的任务是判断在不移除这两块已放置瓦的情况下，是否有可能完全铺满整个屋顶
//t个用例 第一行w,h,a,b 第二行x1, y1, x2, y2左下角坐标
//输出Yes 或者 No
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
using ll = long long;

void solve() {
    ll w, h, a, b;
    cin >> w >> h >> a >> b;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int cnt = 0;
    if (x2 + a <= x1 || x1 + a <= x2) {  //计算差值是否能被整除,可以就能放,满足一个就行
        if (abs(x1 - x2) % a == 0) {
            cout << "Yes\n";
            return;
        }
    } else cnt++;
    if (y1 + b <= y2 || y2 + b <= y1) {
        if (abs(y1 - y2) % b == 0) {
            cout << "Yes\n";
            return;
        }
    } else cnt++;
    cout << (cnt == 2 ? "Yes\n" : "No\n");
}

int main() {
#ifndef ONLINE_JUDGE   
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}