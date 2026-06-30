//有一个排列p
//对于边u,v，if(pu > pv) 该边=x,否则该边=y
//目标是找排列p的最大总和
//输出排列p
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;
vector<vector<int>> g;
vector<int> indeg;  //计算入度
vector<int> res;  //存的是坐标
void bfs(int n) {
    res.clear();
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) que.push(i);
    }
    while (!que.empty()) {
        int u = que.front(); que.pop();
        res.push_back(u);
        for (int v: g[u]) {
            indeg[v]--;
            if (indeg[v] == 0) que.push(v);
        }
    }
    vector<int> p(n + 1);
    for (int i = 0; i < n; i++) {
        p[res[i]] = i + 1;
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << ' ';
        cout << p[i];
    }cout << endl;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n ;
        cin >> n;
        g.assign(n+1, vector<int>());
        indeg.assign(n + 1, 0);
        for (int i = 0; i < n -1; i++) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            if (x > y) {
                g[v].push_back(u);
                indeg[u]++;
            } else {
                g[u].push_back(v);
                indeg[v]++;
            }
        }
        bfs(n);
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
