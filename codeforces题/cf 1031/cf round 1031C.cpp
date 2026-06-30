//矿山是一个大小为 n×m的矩形网格，其中每个格子可能是金矿石、石头或空地
//当炸药在坐标为 (x,y)的空地爆炸时，以该格子为中心、边长为 2k+1的正方形范围内的所有格子都会变成空地
//如果金矿石位于这个正方形内部（不在边界上），它就会消失；
//如果金矿石位于正方形的边界上，斯米洛就能收集到这些黄金
//请你计算斯米洛能收集到的最大黄金数量
//t个用例 n, m, k 表示矿场的行数、列数，以及爆炸参数 k
//n行包含m个字符 .代表空地 #代表石头 g代表金矿
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
using ll = long long;

void check(const vector<string> &g,const vector<vector<int>> &pre,int n, int m,int k) {
    int res = n * m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                int x1 = max(0, i - k + 1);
                int x2 = min(n - 1, i + k - 1);
                int y1 = max(0, j - k + 1);
                int y2 = min(m - 1, j + k - 1); //pre从1开始的，所以加一
                int ans = pre[x2 + 1][y2 + 1] - pre[x2 + 1][y1] - pre[x1][y2 + 1] + pre[x1][y1];
                res = min(ans, res);
            }
        }
    }
    cout << pre[n][m] - res << '\n'; //总数减去引爆的金子的最小值
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    vector<vector<int>> pre(n + 2, vector<int>(m + 2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pre[i + 1][j + 1] = (g[i][j] == 'g' ? 1 : 0) + pre[i][j + 1] + pre[i + 1][j] - pre[i][j];
        }
    }
    check(g, pre, n, m,k);
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