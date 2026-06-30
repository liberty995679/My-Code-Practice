//员工欺压
//员工等级排序
//存在相同等级的员工
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
vector<pair<int, int>> res;
int casenum = 1;
void bfs(int n) {
    res.clear();
    queue<int> que;
    vector<int> cur;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) cur.push_back(i);
    }
    int rank = 1; //bfs层数
    while (!cur.empty()) {
        sort(cur.begin(), cur.end());
        for (int employ: cur) {
            res.push_back({rank, employ});  //层数，员工号
        }
        vector<int> next_level;   //下一层
        for (int u: cur) {
            for (int v: g[u]) {
                indeg[v]--;
                if (indeg[v] == 0) {
                    next_level.push_back(v);
                }
            }
        }
        cur = next_level;
        rank++;
    }
    cout << "Scenario #" << casenum++ << ":" << endl;
    for (auto i: res) {
        cout << i.first << ' ' << i.second << endl;;
    }
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;
        g.assign(n + 1, vector<int>());
        indeg.assign(n + 1, 0);
        for (int i = 0; i < r; i++) {
            int r1 , r2;
            cin >> r1 >> r2;
            g[r2].push_back(r1);
            indeg[r1]++;
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
