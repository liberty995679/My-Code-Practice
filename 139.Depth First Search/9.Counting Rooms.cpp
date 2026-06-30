//网格图连通记块数,输入n * m的方格
//输出.连通的房间数量
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
using ll = long long;
int n, m;
vector<string> g;
bool visited[1000][1000];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
int res = 0;
void dfs(int u, int v) {
    visited[u][v] = true;
    for (int i = 0; i < 4; i++) {
        int nx = u + dx[i];
        int ny = v + dy[i];  //加边界判断,防止越界
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (!visited[nx][ny] && g[nx][ny] == '.') {
            dfs(nx, ny);
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
    g.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.' && !visited[i][j]) {
                res++;    //发现新房间
                dfs(i, j);
            }
        }
    }
    cout << res << endl;
    return 0;
}