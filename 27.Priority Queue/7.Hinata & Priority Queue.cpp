//计算数组里第一大 第二大 第三大的数的乘积
//范围是 0 到 i
//如果前两个没有输出-1
//每一个结果都要输出
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

void solve() {
    int n;
    cin >> n ;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    priority_queue<ll> pq;
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if (pq.size() < 3) cout << -1 << '\n';
        else {
            ll a = pq.top(); pq.pop();
            ll b = pq.top(); pq.pop();
            ll c = pq.top(); pq.pop();
            ll res = a * b * c;
            cout << res << '\n';
            pq.push(a); pq.push(b);
            pq.push(c);
        }
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