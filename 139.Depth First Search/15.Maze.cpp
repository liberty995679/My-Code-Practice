//在n * m的方格中，把k个空地变成墙，使得剩下的空地形成一个区域
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
using ll = long long;
const int MAXIN = 2e5 + 1;   
vector<string> arr;
vector<vector<bool>> vis;
stack<pair<int, int>> sta;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m, k;
void dfs(int x, int y) {
    vis[x][y] = true;
    sta.push({x, y});
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
        if (!vis[nx][ny] && arr[nx][ny] == '.') dfs(nx, ny);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    vis.assign(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        arr.push_back(s);
    }
    bool flag = false;   //dfs只用一次
    for (int i = 0; i < n && !flag; i++) {
        for (int j = 0; j < m && !flag; j++) {
            if (arr[i][j] == '.') {
                dfs(i, j);
                flag = true;
            }
        }
    }
    while (k-- && !sta.empty()) {
        auto t = sta.top();
        int x1 = t.first;int y1 = t.second;
        arr[x1][y1] = 'X';
        sta.pop();
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}