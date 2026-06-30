//给出棋盘上两个格子（例如 a1、h8）
//求骑士（Knight）从起点走到终点所需的最少步数
//棋盘大小是标准的 8×8（列 a 到 h，行 1 到 8）
//每个结果单独一行输出最小步数
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector> 
#include <string>   
#include <map>
#include <set>
using namespace std;
using ll = long long; 
vector<vector<int>> g;
vector<vector<int>> dist;
int dx[8] = {1, 2, -1, -2, 1, 2, -1, -2};
int dy[8] = {2, 1, 2, 1, -2, -1, -2, -1};

void bfs (int x, int y, int x0, int y0){
    queue<pair<int, int>> que;
    que.push({x, y});
    dist[x][y] = 0;
    while (!que.empty()) {
        auto w = que.front();
        que.pop();
        int u = w.first;
        int v = w.second;
        if (u == x0 && v == y0) return;
        for (int i = 0; i < 8; i++) {
            int tx = u + dx[i];
            int ty = v + dy[i];
            if (tx < 0 || tx >= 8 || ty < 0 || ty >= 8) continue;
            if (dist[tx][ty] == -1) {
                dist[tx][ty] = dist[u][v] + 1;
                que.push({tx, ty});
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
    int t;
    cin >> t;
    while (t--) {
        g.assign(8, vector<int>(8));
        dist.assign(8, vector<int>(8, -1));
        string a, b;
        cin >> a >> b;
        int x1 = a[0] - 'a';  int y1 = a[1] - '1';
        int x2 = b[0] - 'a'; int y2 = b[1] - '1'; 
        if (x1 < 0 || x1 >= 8 || y1 < 0 || y1 >= 8) {
            cout << -1 << endl;
            continue;
        }
        if (x2 < 0 || x2 >= 8 || y2 < 0 || y2 >= 8) {
            cout << -1 << endl;
            continue;
        }
        bfs(x1, y1, x2, y2);
        cout << dist[x2][y2] << endl;
    }
    return 0;
}