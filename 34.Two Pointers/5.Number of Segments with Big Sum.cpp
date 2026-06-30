//双指针,求大于等于s的数组数的总和的数量
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll solve(const vector<ll> &a, ll s) {
    int l = 0;
    int n = a.size();
    ll sum = 0;
    ll res = 0;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (sum >= s) {
            res += (n  - r);
            sum -= a[l];
            l++;
        }
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
    cout << solve(a, s) << '\n';
    return 0;
}