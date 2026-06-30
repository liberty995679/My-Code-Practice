//输入一个n(0 <= n <= 1e100000)
//计算数位之和
//需要几次才能变成个位数
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
using ll = long long;
void solve() {
    string n;
    cin >> n;
    int res = 0;
    while (n.size() > 1) {
        ll sum = 0;
        for (char c: n) {
            ll x = c - '0';
            sum += x;
        }
        n = to_string(sum);
        res++;
    }
    cout << res << endl;
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