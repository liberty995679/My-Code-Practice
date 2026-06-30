//输入n q n个整数 q个查询
//0 t x 表示插入x到 qt
//1 t 表示获取最大值
//2 t 表示删除最大值
//只输出获取最大值
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
    int n, q;
    cin >> n >> q;
    vector<priority_queue<int>> pq(n);
    while (q--) {
        int c;
        cin >> c;
        if (c == 0) {
            int t, x; cin >> t >> x;
            pq[t].push(x);
        } else if (c == 1) {
            int t; cin >> t;
            if (!pq[t].empty()) {  //一定要判断空不空
                cout << pq[t].top() << '\n';
            }
        } else {
            int t; cin >> t;
            if (!pq[t].empty()) {
                pq[t].pop();
            }
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