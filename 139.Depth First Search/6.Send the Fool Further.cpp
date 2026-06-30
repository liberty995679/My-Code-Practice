//接力传信, 输入 u v c,u和v是直接认识的朋友，两者之间的花费为c
//主角从0开始传信，求最大能花费的费用
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
const int MAXIN = 1e5 + 1;
vector<pair<int,int>> adj[MAXIN];   //另一位同学和费用
vector<bool> visited(MAXIN);
int ans = 0;
void dfs(int u, int c) {
    visited[u] = true;
    ans = max(ans, c);
    for (auto v : adj[u]) {
        if (!visited[v.first]) {
            dfs(v.first, c + v.second);
        }
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
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dfs(0, 0);
    cout << ans << endl;
}