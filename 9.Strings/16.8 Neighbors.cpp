//输入一个n * m的格子
//该格子只包含"x""."
//输入(x, y)坐标,从1开始
//判断坐标周围是不是都是x 如果是 输出yes 否则no
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <cctype>
using namespace std;

vector<int> pos = {-1, 0, 1};

bool convert(vector<string> &a, int x, int y, int n, int m) {
    int idx, idy;
    for (int i: pos) {
        for (int j : pos) {
            if (i == 0 && j == 0) continue;
            idx = x + i;
            idy = y + j;
            if (idx < 0 || idx >= n || idy < 0 || idy >= m) continue;
            if (a[idx][idy] == '.') return false;
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int x, y;
    cin >> x >> y;
    bool flag = convert(arr, x - 1, y - 1, n, m);
    if (flag) cout << "yes\n";
    else cout << "no\n";
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