//输入一个数组b
//数组a满足ai 整除 ai+1 的性质
//b为a 中的某些数乘以x得到的
//计算x可能的值输出一个
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
        int n;
        cin >> n;
        vector<ll> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];
        ll g = 0;  // 从当前位置到末尾的gcd
        ll lc = 1;  // 维护最终的最小公倍数，即x的可能值
        for (int i = n - 1; i >= 0; i--) {
            g = gcd(g, b[i]);  //负责提取当前后缀的公共因子，（过滤掉了 x）。
            lc = lcm(lc, b[i] / g); //lcm 负责收集所有“公共因子覆盖不到、但必须保留”的因子，并以最小方式合并
        }
        cout << lc << endl;
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