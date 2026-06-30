//从第1个盒子出发,用最少步数打开第N个盒子(宝藏所在)
//输出:最少打开的盒子数量
//打开盒子的顺序(字典序最小)
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>   
#include <map>
#include <set>
using namespace std;
using ll = long long; 
vector<vector<int>> g;                    // 地图:存储每个格子的状态('.' 空地, '*' 障碍, 'X' 起点)
vector<int> dis;                   // dis[i][j] = 从起点到(i,j)的最短距离
vector<int> vis;
int dx[4] = {1, 0, 0, -1};                 // 四个方向的x偏移:下、左、右、上
int dy[4] = {0, -1, 1, 0};                 // 四个方向的y偏移:下、左、右、上
int n;
vector<int> parent;
void bfs(int u) {
    parent.assign(n + 1, -1);
    vis.assign(n + 1, 0);
    queue<int> que;
    que.push(u);
    vis[u] = 1;
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        if (p == n) break;  // 找到目标
        for (int v: g[p]) {
            if (!vis[v]) {
                vis[v] = 1;
                que.push(v);
                parent[v] = p;
                if (v == n) goto done;
            }
        }
    }done:;
    if (!vis[n]) {
        cout <<  -1 << endl;
        return;
    }
    int v = n;
    vector<int> path;
    while (v!= -1) {  //路径回溯
        path.push_back(v);
        v = parent[v];
    }
    reverse(path.begin(), path.end());
    cout << path.size() - 1 << endl;
    for (int i =0; i < path.size() - 1; i++) {
        cout << path[i] << ' ';
    } cout << endl;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        g.assign(n + 1, vector<int>());
        for (int i  = 1 ; i <= n - 1; i++) {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++) {
                int  x;
                cin >> x;
                g[i].push_back(x);
            }
            sort(g[i].begin(), g[i].end());
        }
        bfs(1);
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