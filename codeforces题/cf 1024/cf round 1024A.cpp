//输入n m p q
//表示n个数，m为数组总和，p个连续段之和为q
//判断是否可以构造出满足条件的数组
//如果存在 输出YES 
//否则输出NO
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <utility>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;

void solve() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    if (n % p == 0 && (n / p) * q != m) {  //能整除区间总和等于m
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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