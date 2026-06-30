//MEX 代表最小的没有出现过的整数
//有n^2张卡片,上面的数字分别是0 - n ^ 2 - 1
//任务是安排卡片的位置
//使得所有可能的子网格的MEX值的总和最大
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <utility>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n, -1));
    int x;
    int y;
    if (n % 2 == 0) {
        x = n / 2 - 1;
        y = n / 2 - 1;
    } else {
        x = n / 2;
        y = n / 2;
    }
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    int t = 0;
    int step = 1;
    int idx = 0;  //当前方向编号
    g[x][y] = t++;
    while (t < n * n) {
        for (int p = 0; p < 2 && t < n * n; p++) { //两个方向
            for (int i = 0; i < step; i++) { // 在当前方向走 step 步
                if (t >= n * n) break;
                x += dx[idx];
                y += dy[idx];
                if (x >= 0 && x < n && y >= 0 && y < n) {
                    g[x][y] = t++;
                }
                if (t >= n * n) break;
            }
            idx = (idx + 1) % 4;
        }
        step++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j] << " \n"[j + 1 == n];
        };
    }cout << '\n';
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
        solve();
    }
    return 0;
}