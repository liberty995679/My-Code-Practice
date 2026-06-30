//保持图仍然是二分图，那么你只能在同属不同集合的点之间加边。
//输出要补的边的数量
//二分图+补图,就是计算集合A * 集合B - (n - 1)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int MAXIN = 2e5 + 1;   
vector<int> arr[MAXIN];
vector<bool> visited(MAXIN);
vector<int> res(MAXIN, 0);
bool flag = false;

void dfs(int u, int c) {
    res[u] = c;
    for (auto &v : arr[u]) {
        if (res[v] == 0) dfs(v, 1 - c);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int j = 0; j < n - 1; j++) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(1, 0);
    ll cnta = 0;ll cntb = 0;
    for (int i = 1; i <= n; i++) {
        if (res[i] == 0) cnta++;
        if (res[i] == 1) cntb++;
    }
    ll ans = cnta * cntb - (n - 1);
    cout << ans << endl;
    return 0;
}