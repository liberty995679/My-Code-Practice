//一场竞赛，参与者有n个人
//聊天中的参与者按照活跃度排成一个顺序
//但每个人看到的列表中，自己都会排在最上面。
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
vector<vector<int>> g;
vector<int> indeg;  //计算入度
vector<int> res;

void bfs(int n) {
    res.clear();
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) que.push(i);
    }
    while (!que.empty()) {
        int u = que.front(); que.pop();
        res.push_back(u);
        for (int v: g[u]) {
            indeg[v]--;
            if (indeg[v] == 0) que.push(v);
        }
    }
    // for (int i: res) {
    //     cout << i << ' ';
    // }cout << endl;
    if (res.size() == n) cout << "YES" << endl;
    else cout << "NO" << endl;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        g.assign(n + 1, vector<int>());
        indeg.assign(n + 1, 0);
        vector<vector<int>> arr(k, vector<int>(n, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < k; i++) {
            for (int j =1; j < n - 1; j++) {
                int x = arr[i][j];
                int y = arr[i][j + 1];
                g[x].push_back(y);
                indeg[y]++;
            }
        }
        bfs(n);
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
