//输入n k
//计算n的第k小的约数
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <stack>
#include <unordered_map>
#include <climits>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr;
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            arr.push_back(i);
            if (n / i != i) arr.push_back(n / i);
        }
    }
    sort(arr.begin(), arr.end());
    if (arr.size() < k) {
        cout << -1 << endl;
        return;
    }
    cout << arr[k - 1] << endl;
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