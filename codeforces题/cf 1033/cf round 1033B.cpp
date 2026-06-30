//Aryan 和 Harshith玩台球，他们使用的是一张边长为 s的固定正方形台球桌
//四个角分别位于 (0,0)、(0,s)、(s,0)和 (s,s)，这些位置设有球袋。
//在这个游戏变体中，有 n个相同的球被放置在台面上，它们的坐标是整数，并且没有任何球位于台面的边缘或角落。
//随后，所有球同时以每秒 10 ^ 100的速度发射，方向仅限与坐标轴呈 45∘的方向。
//球和球袋几乎可以被视为点状物体，碰撞是完全弹性的——也就是说，球碰到任意边界时会以相同角度和速度反弹。
//Harshith 负责击球，他向 Aryan 提供了球的初始位置和发射角度。请你帮助 Aryan 计算有多少个球最终掉入球袋。
//题目保证不会出现多个碰撞在同一时刻、同一位置发生的情况。
//t个用例 n s 表示球的数量和正方形台球桌的边长
//每行dx,dy,x,y 表示球在 X轴和 Y轴方向的发射方向向量，以及第 i个球的初始位置。保证初始时刻没有两个球重合
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
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
    ll n, s;
    cin >> n >> s;
    ll dx, dy, x, y;
    ll cnt = 0;
    for (int i = 0; i < n ; i++) {
        cin >> dx >> dy >> x >> y;
        if (dx == dy) {  //斜率为 +1 左下到右上
            if (x == y) cnt++;
        } else {            //斜率为 -1 左上到右下
            if (x + y == s) cnt++;  
        }
    }
    cout << cnt << enl;
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