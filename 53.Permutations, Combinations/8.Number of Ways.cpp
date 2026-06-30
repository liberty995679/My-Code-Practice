//集合A包含(0,1)...(0,n),集合B包含(k,1)...(k,n)
//从A中每个点到B中每个点，求所有路径数之和
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXIN = 2e6 + 5;
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

ll C(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k]% MOD;
}
//横向走k步,纵向走|i-j|步,一共k+|i-j|步，除以原阶乘,得到两点之间路径数C(k+|i-j|,k)
void solve(int n, int k) {   //用n^2会超时,所以要优化
    ll res = 0;              //将d=|i-j| ,那么每对路径数=C(k+d,k)
    res = (res + (ll)n * C(k, k)) % MOD;  //当d = 0时，有n对
    for (int d = 1; d < n; d++) { //d的范围是1到n-1
        ll pairs = 2 * (n - d) % MOD;  //求对数，考虑到绝对值，正负会出现两对
        ll load = C(k + d, k) % MOD;   //求每对的路径数
        res = (res + pairs * load) % MOD;
    }
    cout << res << endl;
}

int main() {                    
#ifndef ONLINE_JUDGE            
    freopen("in.txt", "r", stdin);  
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin >> t;
    while (t--) {
        int n, k;          //用O(n)会超时
        cin >> n >> k;    //看笔记，将求和项推导成封闭公式
        cout << (2 * C(k + n + 1, k + 2) - n + MOD) % MOD << endl;
    }
}