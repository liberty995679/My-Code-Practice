//进程n 时间片p
//输入n个进程的名称和时间
//对于每个进程，按顺序打印其名称和进程完成的时间
//如果进程没有完成会被中断然后回到队列
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
    queue<pair<string, int>> que;
    for (int i = 0; i < n; i++) {
        string s; int a;
        cin >> s >> a;
        que.push({s, a});
    }
    int res = 0;
    while (!que.empty()) {
        auto it = que.front();
        que.pop();
        if (it.second > q) { //必须大于q 否则死循环
            res += q;
            it.second -= q;
            que.push({it.first, it.second});
        } else {
            res += it.second;
            cout << it.first << ' ' << res << '\n';
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