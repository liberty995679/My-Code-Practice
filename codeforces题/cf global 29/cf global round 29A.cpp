//你在坐标 (0,0)处，想要到达 (x,y)。
//为此，你可以执行一系列移动步骤。
//每一步需要沿 x轴或 y轴的正方向移动一个正整数长度的距离。
//第一步必须沿 x轴，第二步沿 y轴，第三步再沿 x轴，依此类推。
//也就是说，如果按执行顺序将步骤从 1 开始编号，那么奇数步必须沿 x轴，偶数步必须沿 y轴。
//此外，每一步的长度必须严格大于前一步的长度。
//输出到达 (x,y)所需的最少步数，如果不可能则输出 −1
//t个用例 每一个x y
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
    int x, y;
    cin >> x >> y;
    if (x < y && y > 1) {
        cout << 2 << '\n';
    } else if (x > y && (x - y) > 1 && (y > 1)) {
        cout << 3 << '\n';
    } else {
        cout << -1 << '\n';
    }
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