//公园漫游,输出最小的字典序序列
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
using ll = long long;
const int MAXIN = 1e5 + 1;  //所有邻点按最小顺序深度优先，那是dfs的思想
vector<bool> vis;  //在所有能到的点里面挑最小的,这是bfs的思想
vector<vector<int>> g;
vector<int> res;
void bfs() {
    priority_queue<int, vector<int>, greater<int>> pq;
    vis[1] = true;
    pq.push(1);
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        res.push_back(u);
        for (auto v: g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                pq.push(v);
            }
        }
    }
}

int main()  {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vis.assign(n + 1, false);
    g.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs();
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) cout << ' ';
    }
    return 0;
}