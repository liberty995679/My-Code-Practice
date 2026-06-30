//汉诺塔问题
//n个圆盘 ， 放在左 中 右 三个塔
//初始所有圆盘从小到大按顺序放在左边圆盘
//目标将左边塔的盘 通过 中间塔 移动到 右边塔
//计算最少的移动次数k
//输出 a b 表示从a塔移动到b塔
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <unordered_map>
#include <climits>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int cnt = 0;
vector<pair<int, int>> arr;
void dfs(int n, int left, int mid, int right) {
    if (n == 0) return;
    dfs(n - 1, left, right, mid);
    cnt++;
    arr.push_back({left, right});
    dfs(n - 1, mid, left, right);
}

void solve() {
    int n;
    cin >> n;
    dfs(n, 1, 2, 3);
    cout << cnt << endl;
    for (auto& i: arr) {
        cout << i.first << ' ' << i.second << '\n';
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