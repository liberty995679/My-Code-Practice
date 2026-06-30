//高桥制作了一款游戏，玩家在一个坐标平面上控制一条龙。
//这条龙由编号为 1到 N的 N个部分组成，其中第 1部分称为龙头。
//初始时，第 i部分位于坐标 (i,0)。需要处理 Q条查询，具体如下：
//1 C：将龙头沿方向 C移动 1个单位。这里 C是 R、L、U、D 中的一个，
//分别表示正 x方向、负 x方向、正 y方向和负 y方向。除了龙头之外的每个部分都会移动到它前方部分原来的位置。
//也就是说，第 i部分（2≤i≤N）会移动到第 i−1部分移动前的坐标。
//2 p：查询第 p部分的坐标。
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
    int n, q;
    cin >> n >> q;
    int t, p; 
    char c;
    deque<pair<int, int>> arr(n);
    int cur = 1;
    for (int i = 0; i < n; i++) {
        arr[i] = {cur++, 0};
    }
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> c;
            arr.pop_back();
            auto it = arr.front();
            if (c == 'U') {
                it.second++;
            } else if (c == 'D') {
                it.second--;
            } else if (c == 'L') {
                it.first--;
            } else {
                it.first++;
            }
            arr.push_front(it);
        } else {
            cin >> p;
            cout << arr[p - 1].first << ' ' << arr[p - 1].second << enl;
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