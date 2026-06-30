//骑士可以走8个方向
//求他到目的地的最短路径
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>   
#include <map>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long; 
unordered_map<string, int> id;               // 原始节点编号 -> 紧凑索引映射
vector<vector<int>> adj;                  // 邻接表:存储图的边关系
vector<pair<int, int>> edges;             // 边列表:存储所有输入的边
vector<vector<int>> dist;                         // dist[i] = 从起点到节点i的最短距离
int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
int bfs(int x, int y, int x1, int y1) {
    dist.assign(8, vector<int>(8, -1));
    queue<pair<int, int>> que;
    que.push({x, y});
    dist[x][y] = 0;
    while (!que.empty()) {
        auto p = que.front();
        int u = p.first;
        int v = p.second;
        if (u == x1 && v == y1) return dist[x1][y1];
        que.pop();
        for (int i = 0; i < 8; i++) {
            int u1 = u + dx[i];
            int v1 = v + dy[i];
            if (u1 < 0 || u1 > 7 || v1 < 0 || v1 > 7) continue;
            if (dist[u1][v1] == -1) {
                dist[u1][v1] = dist[u][v] + 1;
                que.push({u1, v1});
            }
        }
    }
    return dist[x1][y1];
}


void solve() {
    string a, b;
    while (cin >> a >> b) {
        int xx = a[0] - 'a'; int yy = a[1] - '1';
        int xx1 = b[0] - 'a'; int yy1 = b[1] - '1';
        int res = bfs(xx, yy, xx1, yy1);
        cout << "To get from "<< a << " to "<< b << " takes " << res <<  " knight moves." << endl;
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