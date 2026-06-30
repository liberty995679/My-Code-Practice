//t个用例 n长度 字符串s包含0 和 1
//1和1之间要隔着至少一个0，就是交替，不能有两个相邻的1
//计算座位的最小值
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <utility>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '1' + s + '1';
    int ans = 0;
    int l = 0;   //计算0的连续段 ， l 为区间
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') ans++;   //从1开始遍历  用1分割
        else {
            if (s[i - 1] == '1') l = i;  // l开始
            if (s[i + 1] == '1') {
                int len = i - l + 1;  //连续区间长度
                int c = (l == 1) + (i == n);  //如果在边界就加上， 原边界为 1, 2, .... n
                ans += (len + c) / 3;
            }
        }
    }
    cout << ans << '\n';
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