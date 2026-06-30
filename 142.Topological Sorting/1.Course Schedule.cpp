//拓扑排序
//a必须在b前面
//如果这些要求互相矛盾（形成环）就输出 IMPOSSIBLE
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
vector<int> vis;
bool hascircle = false;
void dfs(int u) {
    vis[u] = 1;
    for (int v: g[u]) {
        if (vis[v] == 0) {
            dfs(v);
            if (hascircle) return;
        } else if (vis[v] == 1){
            hascircle = true;  //发现环
            return;
        }
    }
    vis[u] = 2;
    res.push_back(u);
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    indeg.assign(n + 1, 0);
    vis.assign(n + 1, false);
    for (int i  = 0; i < m ; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            dfs(i);
            if (hascircle) break;
        }
    }
    if (hascircle) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for (int i : res) {
        cout << i << ' ';
    }cout << endl;
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
