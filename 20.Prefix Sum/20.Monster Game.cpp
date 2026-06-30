//n把剑 i剑强度为ai
//击败i关的怪物需要bi次剑击
//游戏开始前可以选择难度等级x
//强度小于x的剑无法造成伤害
//游戏得分 == x * (你完成的关卡数)
//选择游戏难度，使得得分最大化
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
#include <climits>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n + 1);    
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        vector<ll> prefixb(n + 1);
        for (int i = 1; i <= n; i++) {
            prefixb[i] = prefixb[i - 1] + b[i];
        }
        sort(a.begin(), a.end());
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll x = a[i];   //强度
            int k = n - i;  //可用剑数
            int m = upper_bound(prefixb.begin(), prefixb.end(), k) - prefixb.begin() - 1; //在 b 的前缀和数组 里找 ≤ k 的元素个数
            ans = max(ans, x * m);
        }
        cout << ans << '\n';
    }
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