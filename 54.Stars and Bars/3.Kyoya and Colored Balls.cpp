//有k种颜色，每个颜色球数量不一样，对其排列组合，
//对于每个 i = 1 到 k−1，颜色 i 的最后一个球出现的位置，
//必须严格早于颜色 i+1 的最后一个球出现的位置
//求不同的组合数量
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXIN = 1e6 + 5;
ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return res;
}

vector<ll> fact(MAXIN + 1), invfact(MAXIN + 1);

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

ll A(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[n - k] % MOD;
}
ll C(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k]% MOD;
}

int main() {                    
#ifndef ONLINE_JUDGE            
    freopen("in.txt", "r", stdin);  
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    ll k;
    cin >> k;
    vector<int> c(k);
    for (int i = 0; i < k; i++) cin >> c[i];
    ll ans = 1;
    int S = 0; // prefix sum
    for (int i = 0; i < k; i++) {
        int ci = c[i];    //ci 是 颜色i的球数
        int si = S + ci;   //si 是 颜色i的位置
        ans = ans * C(si - 1, ci - 1) % MOD;//除了颜色i的最后一个球，它前面相同颜色球要在si-1范围内组合
        S = si;    
    }
    cout << ans << endl;
}