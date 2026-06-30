//t个例子 输入l r
//找x y (l <= x < y <= r) 满足 l <= lcm(x, y) <= r
//输出x y 如果没有 输出 -1 -1
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <stack>
#include <unordered_map>
#include <climits>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return a / gcd(a, b) * b;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        bool flag = false;
        if (2 * l <= r) {   //如果l 2l 存在说明有结果
            for (int x = l; x < r; x++) {
                if (flag) break;
                for (int y = 2 * l; y <= r; y++) {
                    int ans = lcm(x, y);
                    if (ans >= l && ans <= r) {
                        flag = true;
                        cout << x << ' ' << y << '\n';
                        break;
                    }
                }
            }
        } else {
            cout << -1 << ' ' << -1 << '\n';
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