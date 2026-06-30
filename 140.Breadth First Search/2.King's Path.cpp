//国王棋子移动
//只能走在“允许的格子”里，
//每个区间段 ri, ai, bi 表示第 ri 行、从列 ai 到列 bi 的格子都是允许的。
//可以走8个方向，上下左右，左上左下，右上右下
//求棋王从起点走到终点所需的最少步数
//如果没有输出-1
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>    
#include <map>
#include <set>
using namespace std;
using ll = long long; 
const int MAXIN = 1e9 + 1;   //直接用二维内存会爆炸
map<pair<int, int>, int> dist;
set<pair<int, int>> vis;   //存允许的格子
queue<pair<int, int>> q;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, -1, 0, 1, -1, 1, 1, -1};
void bfs(int x, int y, int aimx, int aimy) {
    q.push({x, y});
    dist[{x, y}] = 0;
    while (!q.empty()) {
        auto w = q.front();
        q.pop();
        int u = w.first;
        int v = w.second;
        if (u == aimx && v == aimy) return;
        for (int tx = 0; tx < 8; tx++) {
            int xx = u + dx[tx];
            int yy = v + dy[tx];
            if (xx < 1 || xx > MAXIN || yy < 1 || yy > MAXIN) continue;
            if (vis.count({xx, yy}) == 1 && dist.count({xx, yy}) == 0) {
                q.push({xx, yy});
                dist[{xx, yy}] = dist[{u, v}] + 1;
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
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        for (int j = a; j <= b; j++) {
            vis.insert({r, j});
        }
    }
    if (!vis.count({x0, y0}) || vis.count({x1, y1}) == 0) { //检查起点终点是否在范围内
        cout << -1 << '\n';
        return 0;
    }
    bfs(x0, y0, x1, y1);
    cout << dist[{x1, y1}] << endl;
    return 0;
}