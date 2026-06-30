//给定一棵树，求白黑平衡子树的数量
//输入的是2到n个的节点的父节点，还有WWBB的字符串表示颜色
//在子树里黑白数量相同为目标
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>    
using namespace std;
#define int long long
using ll = long long; 
vector<vector<int>> g;   
vector<int> arr;
vector<vector<int>> dp; 
string s;
int n;
void dfs(int u, int p) {
    if (s[u] == 'W') {
        dp[u][0] = 1;
        dp[u][1] = 0;
    } else {
        dp[u][1] = 1;
        dp[u][0] = 0;
    }
    for (int v: g[u]) {
        if (v != p) {
            dfs(v, u);
            dp[u][0] += dp[v][0];
            dp[u][1] += dp[v][1];
        }
    }
}

signed main() {    
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        dp.assign(n + 1, vector<int>(2, 0));
        arr.assign(n + 1, 0);
        g.assign(n + 1, {});
        for (int i = 2;i <= n; i++) {
            int x;
            cin >> x;
            g[i].push_back(x);
            g[x].push_back(i);
        }
        cin.ignore();
        cin >> s;
        s = ' ' + s;
        dfs(1, -1);
        int res = 0;
        for (int i = 1 ; i <= n; i++) {
            if (dp[i][0] == dp[i][1]) res++;
        }
        cout << res << endl;
    }
    return 0;
}