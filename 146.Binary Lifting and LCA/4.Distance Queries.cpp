//在n个节点的树里
//节点a和节点b的距离是多少
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, q;
int maxn = 20;
vector<vector<int>> g;
vector<int> depth;
vector<int> parents;
vector<vector<int>> up;
void dfs(int u, int p, int d) {  //当前节点，父节点，深度
    depth[u] = d;
    parents[u] = p;
    up[u][0] = p;
    for (int v: g[u]) {
        if (v != p) dfs(v, u, d + 1);
    }
}

void adfd() { //预处理
    for (int j = 1; j < maxn; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j -1] != -1) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            } else up[i][j] = -1;
        }
    }
}

int lca(int u, int v) { //计算最近公共祖先
    if (depth[u] > depth[v]) swap(u, v);
    int diff = depth[v] - depth[u];
    for (int j = 0; j < maxn; j++) {
        if (diff & (1 << j)) {
            v = up[v][j];
            if (v == -1) break;
        }
    }
    if (u == v) {
        return u;
    }
    for (int j = maxn - 1; j >= 0; j--) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

void solve() {
    cin >> n >> q;
    g.assign(n + 1, vector<int>());
    depth.assign(n + 1, 0);
    parents.assign(n + 1, 0);
    up.assign(n + 1, vector<int>(maxn, -1));
    for (int i =0; i < n -1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1, 0);
    adfd();
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int ans = lca(a, b);
        cout << depth[a] + depth[b] - 2 * depth[ans] << endl;
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