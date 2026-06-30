//n个城市中有m条路，构建任意两个城市的通路,使得任意两城市都有路
//求修路的最小值,以及哪些城市之间要修路
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int MAXIN = 1e5 + 1;
vector<bool> visited(MAXIN);
vector<int> adj[MAXIN];  //邻接表存图

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void solve(int n) {
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            res.push_back(i);
            dfs(i);
        }
    }
    int k = res.size() - 1;
    cout << k << '\n';
    for (int i = 0; i < k; i++) {
        cout << res[i] << ' ' << res[i+1] << '\n';
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve(n);
    return 0;
}