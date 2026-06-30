//统计牌力，在包含n张牌的数组a里，k长度的牌数的最大值为其牌力
//输出每个最大值的总和，并让结果对1e9 + 7取模
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXIN = 1e5 + 5;
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

void solve(int t, int k, const vector<int>& a) {
    ll ans = 0;
    for (int i = 0; i < a.size(); i++) {
        ans = (ans + C(i, k - 1) * a[i]) % MOD;
    }
    cout << "Case #" << t << ": " << ans << endl;
}

int main() {                    //排序排好后，选择C(i, k - 1)
#ifndef ONLINE_JUDGE            //i是指比他小的数的数量，k - 1是除他以外要选择的数量
    freopen("in.txt", "r", stdin);  //c(i, k-1)代表它能被选择几次
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    init();
    for (int t = 1; t <= tt; t++) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        solve(t, k, arr);
    }
}