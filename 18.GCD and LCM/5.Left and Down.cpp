//t个例子 输入a b k <= 1e18
//在(a,b)处的机器人想回到(0,0)
//每次移动(x - dx, y - dy)
// 0 <= dx dy <= k
//如果(dx, dy) 是第一次使用, 则花费1
//计算到达终点的最小总花费
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
        ll a, b, k;
        cin >> a >> b >> k;
        ll g = gcd(a, b);
        ll an = a / g;
        ll bn = b / g;
        if (k >= max(a, b)) {
            cout << 1 << '\n';
        } else if (k >= an && k >= bn) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
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