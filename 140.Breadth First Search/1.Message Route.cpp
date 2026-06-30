//判断能否从电脑 1 走到电脑 n（图上是否存在一条从节点 1 到节点 n 的路径
//如果存在，输出一条节点数最少的路径(即最短路径，按节点数计)
//如果不存在则输出 IMPOSSIBLE
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>    
using namespace std;
using ll = long long; 
vector<vector<int>> g;   
vector<int> dist;     // dist[i] = 从 1 到 i 的最短距离（边数）
vector<int> parent;   // 初始设为 -1，表示“未访问”
queue<int> q;

void bfs(int a) {
    q.push(a);
    dist[a] = 0;
    parent[a] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;  //更新最短节点
                parent[v] = u;   //更新前驱节点
                q.push(v);     //加入队列
            }
        }
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
    g.assign(n + 1, {});
    dist.assign(n + 1, -1);
    parent.assign(n + 1, -1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(1);
    if (dist[n] == -1) {  // BFS 后 dist[n] 仍然是 -1 => 说明 n 不可达
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }     
    vector<int> path;    //从 parent 数组回溯路径
    int p = n;
    while (p != -1) {   
        path.push_back(p);
        p = parent[p];
    }  
    reverse(path.begin(), path.end());              // 因为我们是从 n -> 1 逆序加入的，所以需要反转
    cout << path.size() << endl;
    for (int x: path) cout << x << ' ';
    cout << endl;
    return 0;
}