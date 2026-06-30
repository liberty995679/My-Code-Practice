//n个应用， q个事件
//1 2表示 事件1 应用2有一条通知
//2 2表示 事件2 主人公阅读应用2 的通知
//3 1表示 事件3 阅读前 1 条通知
//每次操作输出还有几条未阅读通知
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <queue>
#include <stack>
#include <utility>
#include <unordered_map>
#include <set>

using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> arr(n + 1);
    vector<int> notice(q + 1);
    vector<bool> read(q + 1, false);
    int cnt = 0;  //每个app的通知编号
    int ptr = 0;
    int ans = 0;
    while (q--) {
        int type, p;
        cin >> type >> p;
        if (type == 1) {
            cnt++;
            ans++;
            notice[cnt] = p;
            arr[p].push_back(cnt); //该应用的各个通知编号
        } else if (type == 2) {
            for (int v: arr[p]) {
                if (!read[v]) {
                    read[v] = true;
                    ans--;
                }
            }arr[p].clear();
        } else {
            while (ptr < p) {
                ptr++;
                if (!read[ptr]) {
                    read[ptr] = true;
                    ans--;
                }
            }
        }
        cout << ans << endl;
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