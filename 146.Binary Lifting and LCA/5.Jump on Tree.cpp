//在n个节点的树里
//找从s到t的第i个节点
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, q;
int maxn = 20;
vector<vector<int>> g;
vector<int> depth;
vector<vector<int>> up;

void dfs(int u, int p, int d) {  //当前节点，父节点，深度
    depth[u] = d;
    up[u][0] = p;
    for (int v: g[u]) {
        if (v != p) dfs(v, u, d + 1);
    }
}

void build() { //预处理   
    for (int j = 1; j < maxn; j++) {
        for (int i = 0; i < n; i++) { //要注意节点是0到n-1还1到n
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

int kth_ancestor(int u, int k) { //找u的第k个祖先
    for (int j = 0; j < maxn; j++) {
        if (k & (1 << j)) {
            u = up[u][j];
            if (u == -1) return -1;
        }
    }
    return u;
}


int getpath(int s, int t, int k) {  //找s到t路径的第k个节点
    int l = lca(s, t);
    int dist_s = depth[s] - depth[l];
    int dist_t = depth[t] - depth[l];
    if (k <= dist_s) {
        return kth_ancestor(s, k);
    } else {
        int remain = k - dist_s; //剩余路径
        int dis = dist_t - remain; //t减去它
        return kth_ancestor(t, dis);
    }
}

void solve() {
    cin >> n >> q;
    g.assign(n + 1, vector<int>());
    depth.assign(n + 1, 0);
    up.assign(n + 1, vector<int>(maxn, -1));
    for (int i =0; i < n -1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1, 0);  //从0开始建树
    build();
    while (q--)
    {
        int s, t, i;
        cin >> s >> t >> i;
        int l = lca(s, t);
        int llenth = depth[s] + depth[t] - 2 * depth[l];
        if (i > llenth) cout << -1 << endl;
        else {
           cout <<  getpath(s, t, i) << endl;
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