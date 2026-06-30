//冰裂，从起点到终点，冰裂开后进入下一层
//"X"表示裂开的冰，"."表示完整的冰
//判断r1,c1 能否到r2,c2
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
using ll = long long;
vector<string> arr(501);
vector<vector<bool>> visited(501, vector<bool>(501, false));
bool g[501][501];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
int n, m, r1, c1, r2, c2;
bool flag = false;
void dfs(int x, int y) {
    visited[x][y] = true;
    if (x == r2 && y == c2) {
        flag = true;
        return;
    }
    if (flag) return;  //剪枝
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if ((nx == r2 && ny == c2) || !visited[nx][ny] && arr[nx][ny] == '.') dfs(nx, ny);
    }  //未访问过的且能继续深度搜索的，还有终点也要搜索
}

int dfs1(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (arr[nx][ny] == '.' || visited[nx][ny]) {  //记录邻居个数，包括已经访问过的
            cnt++;
        }
    }
    return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];   // cin读入不了vector<string>
    }
    cin >> r1 >> c1 >> r2 >> c2;
    r1--; r2--; c1--; c2--;
    dfs(r1, c1);
    if (!flag) cout << "NO" << endl;
    else {
        int res = dfs1(r2, c2);
        if (arr[r2][c2] == 'X') {
            if (res >= 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            if (res >= 2) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}