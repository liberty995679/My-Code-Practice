//给一个图，从A到B
//输出LRUD的路线
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>   
#include <map>
#include <set>
using namespace std;
using ll = long long; 
vector<vector<char>> g;
vector<vector<pair<int, int>>> parent; //存x,y的父节点
vector<vector<int>> dis;
queue<pair<int, int>> que;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;
int xx, yy, xx1, yy1;
void bfs(int x, int y) {
    que.push({x, y});
    dis[x][y] = 0;
    while (!que.empty()) {
        auto h = que.front();
        que.pop();
        int u = h.first;
        int v = h.second;
        for (int i = 0;  i< 4; i++) {
            int u1 = dx[i] + u;
            int v1 = dy[i] + v;
            if (u1 < 0 || u1 >= n || v1 < 0 || v1 >= m) continue;
            if (g[u1][v1] != '#' && dis[u1][v1] == -1) {
                que.push({u1, v1});
                dis[u1][v1] = dis[u][v] + 1;
                parent[u1][v1] = {u, v};
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
    cin >> n >> m;
    g.assign(n, vector<char>(m));
    dis.assign(n, vector<int>(m, -1));
    parent.assign(n, vector<pair<int,int>>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'A') {
                xx = i; yy = j;
            }
            if (g[i][j] == 'B') {
                xx1 = i; yy1 = j;
            }
        }
    }
    bfs(xx, yy);
    if (dis[xx1][yy1] == -1) {
        cout << "NO" << endl;
        return 0;
    } else {
        cout << "YES" << endl;
        cout << dis[xx1][yy1] << endl;
        vector<char> res;
        while (xx1 != xx || yy1 != yy) {
            auto p = parent[xx1][yy1];
            if (xx1 == p.first + 1 && yy1 == p.second) res.push_back('D');
            else if (xx1 == p.first - 1 && yy1 == p.second) res.push_back('U');
            else if (xx1 == p.first && yy1 == p.second + 1) res.push_back('R');
            else res.push_back('L');
            xx1 = p.first; yy1= p.second;
        }
        reverse(res.begin(), res.end());
        for (char& c: res) {
            cout << c;
        }
    }
    return 0;
}