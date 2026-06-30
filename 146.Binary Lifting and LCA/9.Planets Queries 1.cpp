//n个行星,q个查询
//输入行星的传送目的地，行星可以传送自己
//查找行星x传送第k次的目标
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
int n;
int maxn = 30;  //k最大1e9
vector<vector<int>> g;
vector<vector<int>> up;
vector<int> depth;
void dfs(int u, int p, int w) {
    up[u][0] = p;
    depth[u] = depth[p] + 1;
    for (int v: g[u]) {
         dfs(v, u, w);
    }
}

void build() {
    for (int j = 1; j < maxn; j++) {
        for (int i = 1; i <= n; i++) {
                int mid = up[i][j - 1];
                up[i][j] = up[mid][j - 1];
        }
    }
}

int lca(int s, int t) {
    if (depth[s] > depth[t]) swap(s, t);
    int diff = depth[t] - depth[s];
    for (int j = 0; j < maxn; j++) {
        if (diff & (1 << j)) {
            t = up[t][j];
             if (t == -1) break;
        }
    }
    if (s == t) return s;
    for (int j = maxn - 1; j >= 0; j--) {
        if (up[s][j] != up[t][j]) {
            s = up[s][j];
            t = up[t][j];
        }
    }
    return up[s][0];
}


int query(int x, int k) {
    for (int j = 0; j < maxn; j++) {
        if (k & (1 << j)) {
            x = up[x][j];
            if (x == -1) return -1;
        }
    }
    return x;
}

void solve() {
    int q;
    cin >> n >> q;
    g.assign(n+ 1, vector<int>());
    depth.assign(n + 1, 0);
    up.assign(n + 1, vector<int>(maxn, -1));
    for (int i = 1; i <= n; i++) {
        cin >> up[i][0];  // 经过 2^0 = 1 次传送
    }
    build();
    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << query(x, k) << '\n';   
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