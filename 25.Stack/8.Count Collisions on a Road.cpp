//字符串只包含RLS
//分别代表 向右转 向左转 保持不动
//计算会出车祸的车数量
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
#include <set>
using namespace std;
using ll = long long;

void solve() { 
    string s;
    cin >> s;
    int n = s.size();
    int l = 0; int r = n - 1;
    while (l < n && s[l] == 'L') l++;
    while (r >= 0 && s[r] == 'R') r--;
    int ans = 0;
    for (int i = l; i <= r; i++) {
        if (s[i] != 'S') ans++;
    }
    cout << ans << endl;
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