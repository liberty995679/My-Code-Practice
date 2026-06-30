//n个节点,q个查询
//n - 1条边
//每个查询包含起点终点和体力
//判断每次行动的终点
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
int n;
int maxn = 20;  //k最大1e9
vector<vector<int>> g;
vector<vector<int>> up;
vector<int> depth;
void dfs(int u, int p) {
    up[u][0] = p;
    depth[u] = depth[p] + 1;
    for (int v : g[u]) {
        if (v != p) {  // 避免回到父节点
            dfs(v, u);
        }
    }
}

void build() {
    for (int j = 1; j < maxn; j++) {
        for (int i = 1; i <= n; i++) {
            int mid = up[i][j - 1];
            if (mid != -1) {
                up[i][j] = up[mid][j - 1];
            }
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

int query(int s, int t, int k) {
    int l = lca(s, t);
    int dist_s = depth[s] - depth[l];
    int dist_t = depth[t] - depth[l];
     int total = dist_s + dist_t;
    if (k >= total) return t;
    if (k <= dist_s) {
        return kth_ancestor(s, k);
    } else {
        int remain = k - dist_s; //剩余路径
        int dis = dist_t - remain; //t减去它
        return kth_ancestor(t, dis);
    }
}

void solve() {
    int q;
    cin >> n;
    g.assign(n+ 1, vector<int>());
    depth.assign(n + 1, 0);
    up.assign(n + 1, vector<int>(maxn, -1));
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    depth[0] = 0;  // 根节点的父节点深度为-1
    dfs(1, 0);      // 以1为根，0为虚拟父节点
    build();
    cin >> q;
    while (q--) {
        int s, t, k;
        cin >> s >> t >> k;
        cout << query(s, t, k) << '\n';   
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