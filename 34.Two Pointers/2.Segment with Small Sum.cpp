//双指针,求小于等于s的数组连续数的最大值
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

ll solve (const vector<ll> &a, ll s) {
    ll n = a.size();
    ll l = 0;
    ll sum = 0;
    ll res = 0; // 存个数最大
    for (ll r = 0; r < n; r++) {
        sum += a[r];
        while (l <= r && sum > s) { // 要考虑只有一个元素的情况
            sum -= a[l];
            l++;
        }
        res = max(res, r - l + 1);
    }
    return res;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; ll s;
    cin >> n >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(a, s) << endl;
    return 0;
}