//t个例子
//n个节点,m条边,q个查询
//输入s, t, 要找一条 s 到 t 的路径，
//使得路径上最危险（权值最大）的那条路的危险度尽可能小
//最终输出这个危险度。
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
int n;
int maxn = 20;
vector<vector<pair<int,int>>> tree;  //邻接表存树
vector<vector<int>> up;
map<pair<int, int>, int> mp;
vector<vector<int>> mx;
vector<int> depth;
struct Edge {  //定义边结构，代替map
    int u, v, w;
}; 
vector<Edge> edges;  //原图的边
vector<bool> vis;
vector<int> fa;  //并查集

int find(int x) {
    if (fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
void kruskal() {
    sort(edges.begin(), edges.end(), [](const Edge& a,const Edge& b) { return a.w < b.w; });
    fa.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) fa[i] = i;
    tree.assign(n + 1, vector<pair<int,int>>());
    int cnt = 0;
    for (auto &e : edges) {
        int fu = find(e.u);
        int fv = find(e.v);
        if (fu != fv) {
            fa[fu] = fv;
            tree[e.u].push_back({e.v, e.w});
            tree[e.v].push_back({e.u, e.w});
            if (++cnt == n - 1) break;
        }
    }
}

void dfs(int u, int p, int w) {
    up[u][0] = p;
    mx[u][0] = w;
    depth[u] = depth[p] + 1;
    for (auto &e : tree[u]) {
        int v = e.first;
        int cost = e.second;
        if (v != p) dfs(v, u, cost);
    }
}

void build() {
    for (int j = 1; j < maxn; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j-1] != -1) { 
                int mid = up[i][j - 1];
                up[i][j] = up[mid][j - 1];
                mx[i][j] = max(mx[i][j - 1], mx[mid][j - 1]);    
            }
        }
    }
}

int query(int s, int t) {
    if (s == t) return 0;
    int max_edge = 0;
    if (depth[s] > depth[t]) swap(s, t);
    int diff = depth[t] - depth[s];
    for (int j = 0; j < maxn; j++) {
        if (diff & (1 << j)) {
            max_edge = max(max_edge, mx[t][j]);
            t = up[t][j];
             if (t == -1) break;
        }
    }
    if (s == t) return max_edge;
    for (int j = maxn - 1; j >= 0; j--) {
        if (up[s][j] != up[t][j]) {
            max_edge = max(max_edge, mx[s][j]);
            max_edge = max(max_edge, mx[t][j]);
            s = up[s][j];
            t = up[t][j];
        }
    }
    max_edge = max(max_edge, mx[s][0]);
    max_edge = max(max_edge, mx[t][0]);
    return max_edge;
}

void solve() {
    int t;
    cin >> t;
    int casenum = 1;
    while (t--) {
        int m;
        cin >> n >> m;
        edges.clear();
        mp.clear();
        depth.assign(n + 1, 0);
        depth[0] = -1;
        up.assign(n + 1, vector<int>(maxn, -1));
        mx.assign(n + 1, vector<int>(maxn, 0));       
        for (int i = 0; i < m; i++) {
            int x, y, d;
            cin >> x >> y >> d;
            edges.push_back({x, y, d});
        }
        kruskal();
        dfs(1, 0, 0);
        build();
        int q;
        cin >> q;
        cout << "Case " << casenum++ << ":\n";
        while (q--) {
            int s, t;
            cin >> s >> t;
           cout << query(s, t) << "\n";
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}