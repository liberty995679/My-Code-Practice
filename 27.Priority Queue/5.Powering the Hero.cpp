//有一副包含 n​ 张牌的牌堆，每张牌都有一个“力量值”。牌分为两种类型：
//英雄牌：这种牌的力量值始终等于 0；
//奖励牌：这种牌的力量值始终为正数。
//你可以对这副牌执行以下操作：
//从牌堆顶部取一张牌；
//如果这张牌是奖励牌，你可以选择把它放到你的奖励牌堆的顶部，或者直接丢弃；
//如果这张牌是英雄牌，则会将你奖励牌堆顶部的那张牌的力量值加到该英雄牌上
//（如果奖励牌堆不为空），之后将该英雄加入你的军队，并且用掉的奖励牌会被丢弃
//你的任务是利用这些操作，组建一支总力量值最大的军队。
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
    cin >> n;
    priority_queue<ll> pq; //奖励牌堆
    vector<ll> arr(n);
    ll res = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            pq.push(arr[i]);
        } else {
            if (!pq.empty()) {
                res += pq.top();
                pq.pop();
            }
        }
    }
    cout << res << '\n';
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