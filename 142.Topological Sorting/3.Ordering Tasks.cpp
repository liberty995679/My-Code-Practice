//拓扑排序
//n , m , x 在 y 前面完成
// n == 0 && m == 0 结束
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;
using ll = long long;
vector<vector<int>> g;
vector<int> indeg;  //计算入度
vector<int> res;
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
    for (int &i: res) {
        cout << i << ' ';
    }cout << endl;
}

void solve() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m ==0) break;
        g.assign(n + 1, vector<int>());
        indeg.assign(n + 1, 0);
        for (int i  = 0; i < m ; i++) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            indeg[y]++;
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
