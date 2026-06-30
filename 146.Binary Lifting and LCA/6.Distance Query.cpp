//n个整数
//a,b,c, 城市a和城市b之间的路为c长度
//对于给定的k个城市
//找出两座城市之间路径上的最短路径长度和最长路径长度
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int n, q;
int maxn = 20;
vector<vector<int>> g;
vector<int> depth;
vector<vector<int>> up;
map<pair<int ,int>, int> mp;
vector<vector<int>> mxnums; //新加倍增数组
vector<vector<int>> mnnums;
void dfs(int u, int p, int d, int cost) {  //当前节点，父节点，深度, 权值
    depth[u] = d;
    up[u][0] = p;
    mxnums[u][0] = cost;
    mnnums[u][0] = cost;
    for (int v: g[u]) {
        int p_cost = mp[{u, v}];
        if (v != p) dfs(v, u, d + 1 , p_cost);
    }
}

void build() { //预处理   
    for (int j = 1; j < maxn; j++) {
        for (int i = 1; i <= n; i++) { //要注意节点是0到n-1还1到n
            if (up[i][j -1] != -1) {
                int mid = up[i][j - 1];
                up[i][j] = up[up[i][j - 1]][j - 1];  //前半段最大边权, 后半段最大边权
                mxnums[i][j] = max(mxnums[i][j - 1], mxnums[mid][j - 1]);
                mnnums[i][j] = min(mnnums[i][j - 1], mnnums[mid][j - 1]);
            } else {
                up[i][j] = -1;
                mxnums[i][j] = -1;
                mnnums[i][j] = 1e9;
            }
        }
    }
}
pair<int, int> qurry(int u, int v) { //返回最小边值和最大边值
    int max_edge = -1;
    int min_edge = 1e9;
    if (depth[u] > depth[v]) swap(u, v);
    int diff = depth[v] - depth[u];
    for (int j = 0; j < maxn; j++) {  //把v提升到和u一个深度
        if (diff & (1 << j)) {
            max_edge = max(max_edge, mxnums[v][j]);
            min_edge = min(min_edge, mnnums[v][j]);
            v = up[v][j];
            if (v == -1) break;
        }
    }
    if (u == v) {
        return {min_edge, max_edge};
    }
    for (int j = maxn - 1; j >= 0; j--) {
        if (up[u][j] != up[v][j]) {
            max_edge = max(max_edge, mxnums[u][j]);
            max_edge = max(max_edge, mxnums[v][j]);
            min_edge = min(min_edge, mnnums[u][j]);
            min_edge = min(min_edge, mnnums[v][j]);
            u = up[u][j];
            v = up[v][j];
        }
    }
    max_edge = max(max_edge, mxnums[u][0]);
    max_edge = max(max_edge, mxnums[v][0]);
    min_edge = min(min_edge, mnnums[u][0]);
    min_edge = min(min_edge, mnnums[v][0]);
    return {min_edge, max_edge};
}



void solve() {
    cin >> n;
    g.assign(n + 1, vector<int>());
    depth.assign(n + 1, 0);
    up.assign(n + 1, vector<int>(maxn, -1));
    mxnums.assign(n + 1, vector<int>(maxn, 0));
    mnnums.assign(n + 1, vector<int>(maxn, 1e9));
    for (int i =0; i < n -1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        mp[{u, v}] = c;
        mp[{v, u}] = c;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1, 0, 0);  //从0开始建树
    build();
    int k;
    cin >> k;
    while (k--) {
        int d, e;
        cin >> d >> e;
        auto ans = qurry(d, e);
        cout << ans.first << ' ' << ans.second << endl;
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