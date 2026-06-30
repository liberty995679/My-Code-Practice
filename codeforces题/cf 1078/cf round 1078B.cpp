//银行转钱
//计算最大存款
//贪心
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
#include <map>
#include <climits>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<ll> arr(n);
    ll sum = 0;    //能转钱的次数
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i] / x;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll cnt = arr[i] / x;   //当前数
        ll cur = (sum - cnt) * y;  //其他账户可转的钱
        ll total = arr[i] + cur;
        ans = max(ans, total);
    }
    cout << ans << endl;

}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}