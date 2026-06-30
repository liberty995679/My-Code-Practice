//选择数组中的i,j,使得|ai-aj| = max(ap-aq),即数组中的最大差值
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
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

ll A(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[n - k] % MOD;
}
ll C(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k]% MOD;
}

void solve(const vector<int> &a, int diff) {
    int n = a.size();
    map<int, int> m;
    for (int i = 0; i < n; i++) m[a[i]]++;
    int xi = a[0];
    int yi = a[n - 1];
    if (m[xi] == n) {   //考虑全等的情况
        cout << 1LL * n * (n - 1) << endl;  //考虑到整数溢出
        return;
    }
    ll res = C(m[xi], 1) * C(m[yi], 1) * 2;
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        int diff = arr[arr.size()-1]-arr[0];
        solve(arr, diff);
    }
}