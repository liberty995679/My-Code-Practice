#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;
using ll = long long;
vector<vector<int>> dist;
vector<string> g;
vector<vector<pair<int,int>>> change(26);
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<bool> used(26, false);
void bfs(int h, int w) {
    queue<pair<int, int>> que;
    que.push({0, 0});
    dist[0][0] = 0;
    if (g[0][0] != '#' && g[0][0] != '.') {
        int q = g[0][0] - 'a';
        if (!used[q]) {
            used[q] = true;
            for (auto c: change[q]) {
                int l = c.first;
                int r = c.second;
                if (l == 0 && r == 0) continue;
                if (dist[l][r] == -1) {
                    dist[l][r] = 1;
                    que.push({l, r});
                }
            }
        }
    }
    while (!que.empty()){
        auto p = que.front();
        int u = p.first;
        int v = p.second;
        que.pop();
        for (int i =0; i < 4; i++) {
            int u1 = u + dx[i];
            int v1 = v + dy[i];
            if (u1 < 0 || u1 >= h || v1 < 0 || v1 >= w) continue;
            if (g[u1][v1] != '#' && dist[u1][v1] == -1) {
                dist[u1][v1] = dist[u][v] + 1;
                que.push({u1, v1});
            }
        }
        if (g[u][v] != '.') {
            int q = g[u][v] - 'a';
            if (!used[q]) {
                used[q] = true;
                for (auto c: change[q]) {
                    int l = c.first;
                    int r = c.second;
                    if (l == u && r == v) continue;
                    if (dist[l][r] == -1) {
                        dist[l][r] = dist[u][v] + 1;
                        que.push({l, r});
                    }
                }
            }
        }
    }
}

void solve() {
    int h, w;
    cin >> h >> w;
    g.assign(h, "");
    dist.assign(h, vector<int>(w, -1));
    for (int i = 0; i < h; i++) {
        cin >> g[i];
        for (int j  = 0; j < w; j++) {
            if (g[i][j] != '#' && g[i][j] != '.') {
                int p = g[i][j] - 'a';
                change[p].push_back({i, j});
            }
        }
    }
    bfs(h, w);
    cout << dist[h - 1][w - 1] << endl;
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