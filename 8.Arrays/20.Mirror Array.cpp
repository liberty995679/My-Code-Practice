//镜像数组
//输入n * m 的数组
//输出他的镜像数组
//比如  2  3  4  == 4  3  2
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <set>
#include <unordered_map>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    }
    for (auto &a: arr) {
        reverse(a.begin(), a.end());
    }
    for (auto a: arr) {
        for (int i = 0; i < a.size(); i++) {
            if (i > 0) cout << ' ';
            cout << a[i];
        }cout << '\n';
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