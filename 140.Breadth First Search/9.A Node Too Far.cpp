//在这个网络图中，有多少个节点是“不可达”的。
//不可达节点数= 到不了的点，超过步数的点
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>   
#include <map>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long; 
int dx[4] = {1, 0, 0, -1};                 // 四个方向的x偏移:下、左、右、上
int dy[4] = {0, -1, 1, 0};                 // 四个方向的y偏移:下、左、右、上

unordered_map<int, int> id;               // 原始节点编号 -> 紧凑索引映射
vector<vector<int>> adj;                  // 邻接表:存储图的边关系
vector<pair<int, int>> edges;             // 边列表:存储所有输入的边
vector<int> dist;                         // dist[i] = 从起点到节点i的最短距离
int n;                                    // 节点总数
int caseNo = 1;                          // 测试用例编号

int bfs(int start, int ttl) {
    dist.assign(n , -1);
    queue<int> que;
    que.push(start);
    dist[start] = 0;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v: adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                que.push(v);
            }
        }
    }
    int unreachable = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] == -1 || dist[i] > ttl) {
            unreachable++;
        }
    }
    return unreachable;
}

void solve() {
    int nc;
    while ((cin >> nc) && nc != 0) {
        id.clear();
        edges.clear(); edges.reserve(nc);
        int a, b;
        for (int i =0 ; i < nc; i++) {
            cin >> a >> b;
            edges.push_back({a, b});
            if (!id.count(a)) {
                int nid = id.size();
                id[a] = nid;
            }
            if (!id.count(b)) {
                int nid = id.size();
                id[b] = nid;
            }
        }
        n = id.size();
        adj.assign(n, vector<int>());
        for (auto &e: edges) {
            int u = id[e.first];
            int v = id[e.second];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int start, ttl;
        while (cin >> start >> ttl) {
            if (start == 0 && ttl == 0) break;
            int unreachable = 0;
            if (!id.count(start)) {
                unreachable = n;
            } else {
                int s = id[start];
                unreachable = bfs(s, ttl);
            }
            cout << "Case " << caseNo++ << ": " << unreachable
                 << " nodes not reachable from node " << start
                 << " with TTL = " << ttl << ".\n";
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