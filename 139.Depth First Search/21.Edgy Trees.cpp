//在一颗被染色的树上，找到满足特定行走路径的好序列
//树的每一条边是黑色或者是红色
//路径的行走方式是从a1开始，走最短路径到阿a2,最短路径到a3...走最短路径到ak
//如果上述k-1段最短路径的拼接过程中，至少经过了一条黑色边，就是好序列
//要求计算N^K种序列中，“好序列”的总数。由于总数很大，需要取模 10^9 + 7。
#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
using ll = long long;  //总数减去不好的数量
const int MOD = 1e9 + 7;
vector<vector<int>> g;
vector<bool> vis;
ll n, k;
ll notgood = 0;

ll power(int n, int k) {
    ll res = 1;
    while (k > 0) {
        if (k & 1) res = (res * n) % MOD;
        n = (n * n) % MOD;
        k >>= 1;
    }
    return res;
}

int dfs(int u) {
    vis[u] = true;
    ll c = 1;
    for (auto v : g[u]) {
        if (!vis[v]) {
            c += dfs(v);
        }
    }return c;
}

signed main()  {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    int total = power(n, k);
    g.resize(n + 1);
    vis.assign(n + 1, false);
    for (int i =0 ; i < n - 1; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        if (x == 0) {
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int cnt = dfs(i);
            int x = power(cnt, k);
            notgood = (notgood + x) % MOD;
        }
    }
    int res = (total - notgood + MOD) % MOD;
    cout << res << '\n';
    return 0;
}