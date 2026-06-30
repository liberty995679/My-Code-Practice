//输入n k x a b c
//数组长度n 窗口长度k 
//x1 = x, xi = (ax(i - 1) + b) mod c
//以此构造数组
//然后计算所有窗口异或和的异或和
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;

ll culculate(const vector<ll>& a, ll k) {
    int l = 0;
    int n = a.size();
    ll total = 0;
    ll cur = 0;
    for (int r = 0; r < n; r++) {
        if (r - l + 1 > k) {
            cur ^= a[l];
            l++;
        } 
        cur ^= a[r];
        if (r - l + 1 == k) {
            total ^= cur;
        }
    }
    return total;
}

void solve() { 
    ll n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;
    vector<ll> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; i++) {
        arr[i] = (a * arr[i - 1] + b) % c;
    }
    ll ans = culculate(arr, k);
    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}