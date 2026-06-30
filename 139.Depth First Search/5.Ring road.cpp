//输入n个城市，n条单向路和费用
//计算改造成单向环所需要的最小费用
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
const int MAXIN = 1e5 + 1;
vector<pair<int,int>> adj[MAXIN];   //邻居和错误费用
vector<bool> visited(MAXIN);
int ans = 1e9;
void dfs(int x, int f, int c) {   //c是当前累计费用
    if (x == 1) {
        ans = min(ans, c);
        return;
    }
    for (auto v: adj[x]) {
        if (v.first != f)   //f是上一个节点，父亲节点
            dfs(v.first, x, c + v.second);
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
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({b, 0});
        adj[b].push_back({a, cost});  
    }
    dfs(adj[1].front().first, 1, adj[1].front().second);  //从1开始
    dfs(adj[1].back().first, 1, adj[1].back().second);   //一个左边遍历，一个右边遍历
    cout << ans << endl;
    return 0;
}