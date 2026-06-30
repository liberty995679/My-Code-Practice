//计算每个点的最大交替和
//从子节点开始往上计算
//例如4节点到1节点有4个节点,a4= 6, a3 = 2, a2 = 5, a1 = 4;
//a4 - a3 + a2 - a1, 得到4种情况6, 4, 9, 5
//所以a4的最大值为9
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>    
using namespace std;
#define int long long
using ll = long long; 
vector<vector<int>> g;   //树形dp
vector<int> arr;
int n;                 //dp[v][1]: 从 v 出发，v 的系数为负的最大交替和
vector<vector<int>> dp;  //dp[v][0]: 从 v 出发，v 的系数为正的最大交替和
void dfs(int u, int p) {
    dp[u][0] = arr[u];
    dp[u][1] = (-1) * arr[u];
    if (p != -1) {
        dp[u][0] = max(arr[u], arr[u] + dp[p][1]);   //继续往上：av−(p的系数为正的交替和)=av+dp[p][1] 
        dp[u][1] = -arr[u] + dp[p][0];  //继续往上：−av+(p的系数为正的交替和)=−av+dp[p][0]
    }
    for (int v : g[u]) {
        if (v != p) dfs(v, u);
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
        for (int i = 1 ; i <= n; i++) cin >> arr[i];
        for (int i =0;i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1, -1);
        for (int i = 1 ; i <= n; i++) {
            cout << dp[i][0];
            if (i < n) cout << ' ';
        }cout << endl;
    }
    return 0;
}