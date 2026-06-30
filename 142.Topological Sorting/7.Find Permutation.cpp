//axi < ayi
//判断是否存在序列a
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;
vector<set<int>> g;
vector<int> indeg;  //计算入度
vector<int> res;

void bfs(int n, vector<int> &cur) {
    res.assign(n + 1, 0);
    queue<int> que;
  
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) que.push(i);
    }
    int value = 1; // 当前要赋的值
    while (!que.empty()) {
        if (que.size() > 1) {
            cout << "No" << endl;
            return;
        }
        int u = que.front(); que.pop();
        res[u] = value++;
        for (int v: g[u]) {
            indeg[v]--;
            if (indeg[v] == 0) que.push(v);
        }
    }
    if (value != n + 1) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    for (int i = 1; i < res.size(); i++) {
        cout << res[i] << ' ';
    }cout << endl;
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.assign(n + 1, set<int>());
    indeg.assign(n + 1, 0);
    vector<int> cur;
    for (int i = 0; i <= n; i++) cur.push_back(i);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;  //坐标
        if (g[x].count(y) == 0) {
            g[x].insert(y);
            indeg[y]++;
        }
    }
    bfs(n, cur);
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
