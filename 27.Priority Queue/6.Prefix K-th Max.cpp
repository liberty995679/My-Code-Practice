//输入一个序列p
//n代表长度 k代表第几个大的数
//计算序列p 前k个第k大的数
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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    priority_queue<int, vector<int>, greater<int>> pq; //用小根堆即可维护第k大的数
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if (pq.size() > k) pq.pop();
        if (pq.size() == k) {
            cout << pq.top() << '\n';
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