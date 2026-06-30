//拓扑排序
//n , m , x 在 y 前面完成
//如果这些要求互相矛盾（形成环）就输出Sandro fails.
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;
using ll = long long;
vector<vector<int>> g;
vector<int> indeg;  //计算入度
vector<int> res;
void bfs(int n) {
    priority_queue<int, vector<int>, greater<int>> que; //这是按最小字典序输出所以用小根堆
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) que.push(i);
    }
    while (!que.empty()) {
        int u = que.top(); que.pop();
        res.push_back(u);
        for (int v: g[u]) {
            indeg[v]--;
            if (indeg[v] == 0) que.push(v);
        }
    }
    if (res.size() < n) {
        cout << "Sandro fails." << endl;
    } else {
        for (int &i: res) {
            cout << i << ' ';
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    indeg.assign(n + 1, 0);
    for (int i  = 0; i < m ; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        indeg[y]++;
    }
    bfs(n);
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
