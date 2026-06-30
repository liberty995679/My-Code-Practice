//输入一个字符串包含DNA序列
//计算最长重复数
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <unordered_map>
#include <climits>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    char c = s[0];
    int ans = 0;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == c) {
            cnt++;
        } else {
            c = s[i];
            cnt = 1;
        }
        ans = max(ans, cnt);
    }
    ans = max(ans, cnt);
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