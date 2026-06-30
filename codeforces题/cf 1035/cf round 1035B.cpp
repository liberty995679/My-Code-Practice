//给定欧几里得平面上的两个点 (px, py) 和 (qx, qy)。
//你从起点 (px, py) 出发，并将执行 n 次操作。在第 i 次操作中，你必须选择一个点，
//使得你当前位置与该点之间的欧几里得距离恰好为 ai，然后移动到该点。
//判断在执行完所有操作后，是否有可能到达终点 (qx, qy)。
//欧几里得距离：点 (x1, y1) 与点 (x2, y2) 之间的欧几里得距离为 sqrt((x1-x2)^2 + (y1-y2)^2)。
//输入：
//每个测试包含多个测试用例。第一行包含测试用例数量 t (1≤t≤10^4)。接下来是测试用例的描述。
//每个测试用例的第一行包含一个整数 n (1≤n≤10^3) —— 序列 a 的长度。
//第二行包含四个整数 px, py, qx, qy (1≤px,py,qx,qy≤10^7) —— 起点和终点的坐标。
//第三行包含 n 个整数 a1, a2, …, an (1≤ai≤10^4) —— 每次操作要移动的距离。
//保证所有测试用例的 n 之和不超过 2×10^5。
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve(){
    int n;
    cin >> n;
    double px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    vector<ll> arr(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());
    ll dist = abs(px - qx) * abs(px - qx) + abs(py - qy) * abs(py - qy);
    if (dist > sum * sum) {
        cout << "NO" << enl; //距离大于最长路无解
        return;
    }
    ll mx_a = arr[n - 1]; //最长的一条
    if (mx_a > sum - mx_a && (dist < (mx_a - (sum - mx_a)) * (mx_a -  (sum - mx_a)))) {
        cout << "NO" << enl; //小于最短路无解
        return;
    }
    cout << "YES" << enl;
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