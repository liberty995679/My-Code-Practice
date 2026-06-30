//考虑所有满足 1≤a<b≤n 的无序对 (a,b)
//t个例子 输入n
//找出所有这些异或结果 109+7 模中不同值的数量
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <unordered_map>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

ll convert(ll n) { //计算不同异或值的数量
    if (n == 1) return 0;
    if (n == 2) return 1; //统计位数
    ll cnt = 63 - __builtin_clzll(n) + 1; //统计一个 64 位整数，二进制表示中“前导 0”的个数
    ll ans;
    if (!(n & (n - 1))) { //n 是不是 2 的幂
        ans = (1LL << cnt) - 2;
    } else {
        ans = (1LL << cnt) - 1;
    }
    return (ans % MOD + MOD) % MOD;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n; 
        cout << convert(n) << '\n';
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