//国际象棋
//计算马从每个格子到左上角的最短步数
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>   
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
using ll = long long;
int dx[8] = {-1, -1, 1, 1, 2, 2, -2, -2};
int dy[8] = {2, -2, -2, 2, 1, -1, -1, 1};
vector<vector<int>> dist;
void bfs(int n) {
    dist.assign(n, vector<int>(n, -1));
    queue<pair<int, int>> que;
    dist[0][0] = 0;
    que.push({0, 0});
    while (!que.empty()) {
        auto p = que.front();
        que.pop();
        int u = p.first;
        int v = p.second;
        for (int i = 0; i < 8; i++) {
            int u1 = u + dx[i];
            int v1 = v + dy[i];
            if (u1 < 0 || u1 >= n || v1 < 0 || v1 >= n) continue;
            if (dist[u1][v1] == -1) {
                dist[u1][v1] = dist[u][v] + 1;
                que.push({u1, v1});
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    bfs(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << ' ';
        }cout << endl;
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