//烤架有一个特殊之处：每烤完一串烤肉后，它的温度都会下降
//你需要尽可能多地烤制烤肉串，并且你有无限量的两种类型的烤肉串可供选择：
//第一种类型需要在烹饪开始时烤架的温度至少为 a度，烹饪完成后烤架的温度会下降 x度
//第二种类型需要在烹饪开始时烤架的温度至少为 b度，烹饪完成后烤架的温度会下降 y度
//初始时，烤架的温度为 k度。请计算你能烤制的烤肉串的最大总数。
//注意：烤架的温度可以为负数
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
#include <map>
#include <set>
using namespace std;
using ll = long long;

void solve() {
    ll k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    ll ans = 0;
    if (x > y) {  //小的在前面，先降温更小的
        swap(a, b);
        swap(x, y);
    }
    if (k >= a) {
        ll cnt = (k - (a - x)) / x;
        ans += cnt;
        k -= cnt * x;
    }
    if (k >= b) {
        ll cnt = (k - (b - y)) / y;
        ans += cnt;
        k -= cnt * y;
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