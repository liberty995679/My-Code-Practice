//t个用例 n长度 k个操作次数
//每次操作可以使得ai + 1
//计算数组里所有的数的二进制的1的总和最大
//添加1的次数不能超过k
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
#include <map>
#include <set>
using namespace std;
using ll = long long;

int popcount(ll x) {  //返回该数字二进制1的个数
    return __builtin_popcountll(x);
}

ll get_cost(ll n) {
    return (~n) & (n + 1); //一个数加1后的最小花费，即它加1后需要多少次操作比原来1个数多
}

void solve() {  
    ll n, k;
    cin >> n >> k;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>>pq;//用小根堆每次找最小的花费
    vector<ll> arr(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ans += popcount(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        ll cost = get_cost(arr[i]);  //计算每个数的最少花费，然后入堆
        pq.push({cost, i});
    }
    while (!pq.empty() && k > 0) {
        auto it = pq.top(); pq.pop();
        ll cost = it.first;
        int i = it.second;
        if (cost > k) break;
        k -= cost;
        arr[i] += cost;
        ll cost1 = get_cost(arr[i]);
        ans++;
        pq.push({cost1, i});
    }
    cout << ans << '\n';
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