//s为起点 e为终点
//一次可以走1次 2次 3次
//计算有几种走法
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

int dfs(int s, int e) {
    if (s == e) return 1;
    else if (s > e) return 0;
    return dfs(s + 1, e) + dfs(s + 2, e) + dfs(s + 3, e);
}

void solve() {
    int s, e;
    cin >> s >> e;
    int t = dfs(s, e);
    cout << t << endl;
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