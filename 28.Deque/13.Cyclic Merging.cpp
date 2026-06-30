//一个环 ai 与 ai+1 相邻 a0 与 an-1相邻
//选择环上任意一对相邻的元素，设它们的值为 x和 y，
//将它们合并成一个值为 max(x,y)的新元素，合并的代价为 max(x,y)。
//注意：此操作会使环的长度减少 1，并更新相应的相邻关系。
//请计算将环合并成一个元素所需的最小总代价
//t个用例 长度n 输入数组a
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
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
    int n;
    cin >> n;
    deque<int> deq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        deq.push_back(x);
    }
    ll cost = 0;
    vector<ll> arr;
    for (int i = 0; i < n - 1; i++) {
        ll x = max(deq[i], deq[i + 1]);
        arr.push_back(x);
    }
    ll x = max(deq[n - 1], deq[0]);
    arr.push_back(x);
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i++) {
        cost += arr[i];
    }
    cout << cost << enl;
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