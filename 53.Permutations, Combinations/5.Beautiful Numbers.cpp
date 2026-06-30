//一个好数要包含a和b,一个绝妙数本身是好数,它的数位和是好数,求n范围内绝妙数数量，并对1e9 + 7取模
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;  
const int MAXIN = 2e6;   //求得是C(n, m), 数组可能越界

vector<ll> fact(MAXIN + 1), invfact(MAXIN + 1);
ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return res;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i <= MAXIN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invfact[MAXIN] = power(fact[MAXIN], MOD - 2);
    for (int i = MAXIN - 1; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
}

ll C(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
} 

bool panduan(int a, int b, int x) {
    while (x > 0) {
        if (x % 10 == a) {
            x /= 10;
        }else if (x % 10 == b) {
            x /= 10;
        }else {
            return false;
        }
    }
    return true;
}

void solve(int a, int b, int n) {
    int ans = 0;
    for (int i = 0; i <= n; i++) {  // 从i开始遍历
        int s = a * i + (n - i) * b;  //查找符合条件的s
        if (panduan(a, b, s)) ans = (ans + C(n, i)) % MOD;
    }
    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, n;
    init();
    while (cin >> a >> b >> n) {
        solve(a, b, n);
    }
    return 0;
}