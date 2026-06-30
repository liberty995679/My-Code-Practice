//双指针,求大于等于s的数组连续数的最小数
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;


int solve (const vector<ll> &a, ll s) {
    int n = a.size();
    int l = 0;
    ll sum = 0;
    int res = INT_MAX;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (sum >= s) {
            res = min(res, r - l + 1);
            sum -= a[l];
            l++;
        }
    }
    return (res == INT_MAX ? -1: res);   //考虑全部和小于n的情况，那答案为0
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