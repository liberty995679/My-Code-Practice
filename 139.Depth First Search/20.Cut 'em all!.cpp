//给定一棵树，删除最多的边使得所有连通块的大小都是偶数
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
using namespace std;
using ll = long long;
const int MAXIN = 2e5 + 1;   
vector<int> arr[MAXIN];
int res = 0;
int dfs(int u, int p) {
    int rootsize = 1;
    for (auto v : arr[u]) {
        if (v == p) continue;  //跳过父节点
        int childsize = dfs(v, u);
        if (childsize % 2 == 0) res++;
        else {
            rootsize += childsize;
        }
    }
    return rootsize;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n ;
    cin >> n;
    if (n % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    dfs(1, -1);
    cout << res << endl;
    return 0;
}