//t个例子 给定一个n 和 x
//求出三元组(a, b, c)的数量
//满足ab + ac + bc <= n and a + b + c <= x
//a b c全部大于0
//计算数量并输出
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
        int n, x;
        cin >> n >> x;
        ll ans = 0;
        for (ll a = 1; a <= x - 2; a++) {
            for (ll b = 1; b <= x - 2; b++) {
                if (a * b > n) break;   // 剪枝 ：ab 已经超过 n
                ll c1 = (n - a * b) / (a + b);  //c 的两个范围
                ll c2 = x - a - b;
                ll cnt = min(c1, c2);
                if (cnt >= 1) ans += cnt;
            }
        }
        cout << ans << endl;

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