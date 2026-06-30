//金属条焊接
//t个用例
//n表示最终要焊接到的长度
//p个金属条的长度
//输出YES 或者 NO
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_map>
using namespace std;
using ll = long long;

bool convert(const vector<int>& a, int goal) {
    ll n = a.size();
    for (ll i = 0; i < (1 << n); i++) {
        ll sum = 0;
        for (ll bit = 0; bit < n; bit++) {
            if (i & (1 << bit)) {
                sum += a[bit];
            }
            if (sum == goal) return true;
        }
    }
    return false;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        vector<int> arr(p);
        for (int i = 0; i < p; i++) cin >> arr[i];
        bool flag = convert(arr, n);
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}