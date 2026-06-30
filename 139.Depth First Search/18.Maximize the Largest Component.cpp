//输入网格的行和列
//选择将一行或者一列的'.'改成'#'
//输出'#'连接成的最大连通分量的大小
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <unordered_set>
using namespace std;
using ll = long long;  
vector<string> g;
vector<vector<bool>> vis;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
int n, m, maxr, minr, maxc, minc, sz;
vector<int> R, C, freeR, freeC;
void dfs(int x, int y) {
    vis[x][y] = true;
    sz++;
    maxr = max(maxr, x);
    minr = min(minr, x);
    maxc = max(maxc, y);
    minc = min(minc, y);
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if (vis[nx][ny] || g[nx][ny] == '.') continue;
        dfs(nx, ny);
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
        cin >> n >> m;
        R.assign(n + 2, 0); C.assign(m + 2, 0); freeR.assign(n + 2, 0); freeC.assign(m + 2, 0);
        vis.assign(n + 2, vector<bool>(m + 2, false));
        g.resize(n + 2);
        for (int i = 1; i <= n; i++) {
            cin >> g[i];
            g[i] = " " + g[i];
        }
        for (int i = 1 ; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (g[i][j] == '.') {
                    freeR[i]++;
                    freeC[j]++;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (vis[i][j] || g[i][j] == '.') continue;
                sz = 0;
                maxr = -1e9; minr = 1e9;
                maxc = -1e9; minc = 1e9;
                dfs(i, j);
                maxr = min(maxr + 1, n); //扩展一格因为相邻的格子也能连接到这个连通块
                minr = max(minr - 1, 1);
                maxc = min(maxc + 1, m);
                minc = max(minc - 1, 1);
                R[minr] += sz;
                R[maxr + 1] -= sz;
                C[minc] += sz;
                C[maxc + 1] -= sz;
            }
        }int ans = 0;
        for (int i = 1; i <= n; i++) {
            R[i] += R[i - 1];
            ans = max(ans, freeR[i] + R[i]);
        }
        for (int j = 1; j <= m; j++) {
            C[j] += C[j - 1];
            ans = max(ans, freeC[j] + C[j]);
        }
        cout << ans << "\n";
    }
    return 0;
}