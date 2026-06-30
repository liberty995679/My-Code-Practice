//输入n,计算1到n的总和，但是减去2的次方
#include <iostream>

using namespace std;
using ll = long long;

ll power(ll a, ll n) {  //计算快速幂，2的次方
    ll res = 1;
    while (n) {
        if (n & 1) res = res * a;
        a *= a;
        n >>= 1;
    }
    return res;
}

ll suma(ll m) {  //计算2次方的总和
    ll sums = 0;
    for (ll i = 0;; ++i) {
        ll x = power(2, i);
        if (x > m) break;  //如果2次方比m大，直接退出循环
        sums += x;
    }
    return sums;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll zonghe = n * (n + 1) / 2; //总和计算套公式
        cout << zonghe - 2 * suma(n) << endl; //总和减去2倍的数即为结果
    }
    return 0;
}