//Tom 和 Jerry 玩分苹果的游戏
//数组a里i位置有ai个苹果
//Tom 先手 每个回合选择一个ai，即ai = ai - 1
//如果所有ai = 0当前玩家输掉比赛
//如果在拿完苹果后max(a1,a2,…,an) − min(a1,a2,…,an) > k 刚才拿苹果的人输掉比赛
//双方都采取最优策略，输出赢家
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <utility>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    ll mn = *min_element(arr.begin(), arr.end());
    sort(arr.begin(), arr.end());
    arr[n - 1]--;       //删掉一次最大值 - 1
    sort(arr.begin(), arr.end());
    if (arr[n - 1] - mn > k) {
        cout << "Jerry\n";
    } else {
        ll sum = 1;
        for (ll x: arr) {
            sum += x;
        }
        if (sum % 2 == 0) {
            cout << "Jerry\n";
        }else {
            cout << "Tom\n";
        }
    }
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