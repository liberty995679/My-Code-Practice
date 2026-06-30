//一个森林由多个树构成,输入n，输入p[i]
//p[i]表示和i在同一颗树中距离最远的亲戚编号
//求一共有几棵树, n <= 1e4
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
using namespace std;
using ll = long long;
vector<vector<int>> g;
vector<bool> vis;

void dfs(int u) {
    vis[u] = true;
    for (int v: g[u]) {
        if (!vis[v]) dfs(v);
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
    vector<int> p(n + 1);  //计算p[i] == i的数量
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    set<int> s;
    for (int i = 1; i <= n; i++) {
        if (p[i] == i) s.insert(i);
        else {   //因为两边的点都满足条件，取最小值去重
            if (p[p[i]] == i) s.insert(min(i, p[i]));
        }
    }
    cout << s.size() << endl;
    return 0;
}