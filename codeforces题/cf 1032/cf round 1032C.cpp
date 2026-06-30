//给你一个 n 行 m 列的整数矩阵，第 i 行第 j 列的元素是 a[i][j]。
//你可以恰好执行一次以下操作：
//选择两个正整数 1 ≤ r ≤ n 和 1 ≤ c ≤ m。
//对于矩阵中所有满足 i = r 或 j = c 的单元格 (i, j)，将其值 a[i][j] 减 1。
//你需要找到在执行一次这样的操作后，矩阵中最大值的最小可能值
//t个用例 输入n m 输入二维数组a
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
const char enl = '\n';

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            mx = max(mx, arr[i][j]); //记录最大值
        }
    }
    vector<int> rowcnt(n), colcnt(m);
    int total = 0; //最大值总数
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == mx) {
                rowcnt[i]++;
                colcnt[j]++;
                total++;
            }
        }
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = 0;
            if (arr[i][j] == mx) x = 1;  //判断i j 交接处是否有最大值
            int cur = rowcnt[i] + colcnt[j] - x;
            if (cur == total) {
                flag = true;
                break;
            }
        }
    }
    if (flag) cout << mx - 1 << enl;
    else cout << mx << enl;
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