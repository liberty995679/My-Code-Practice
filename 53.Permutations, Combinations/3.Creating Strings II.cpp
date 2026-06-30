//输入字符串，判断字符组成的可能有几种，并对1e9 + 7取模
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

vector<ll> arr(1e6 + 1);
void coeff() {    //预处理阶乘
    arr[0] = 1;    //排列 A(n,k)
    for (ll i = 1; i <= 1e6; i++) {
        arr[i] = (arr[i - 1] * i) % MOD;
    }
}

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;
    }
    return res;
}

void solve(const vector<int> &a, int n) {    //除法取模要用模逆元
    ll x = 1;
    for (int i: a) {
        if (i > 1) x = (x * arr[i]) % MOD;
    }
    ll ans = (power(x, MOD - 2)) % MOD;
    cout << (arr[n] * ans) % MOD << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    coeff();
    while (cin >> str) {
        vector<int> nums(26, 0);
        for (int i = 0; i < str.size(); i++) {
            nums[str[i] - 'a']++;
        }
        solve(nums, str.size());
    }
    return 0;
}