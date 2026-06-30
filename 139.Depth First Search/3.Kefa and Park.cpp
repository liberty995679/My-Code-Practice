//从家到餐馆，构成一个树的关系
//要避开连续超过m个有猫的节点,不是连续的可以走
//n个节点，有猫的等于1，n-1行条可走的路线
//计算他能去餐馆的路线数量
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int MAXIN = 1e5 + 1;
vector<int> adj[MAXIN];
vector<bool> visited(MAXIN);
vector<int> arr(MAXIN);
ll n, m;
int res = 0;
void dfs(int u, int parent, int k) {  //当前节点,父节点,k是连续猫的数量
    if (arr[u] == 1) k++;
    else k = 0;
    if (k > m) return;
    bool leaf = true; //判断是否为叶子节点
    for (int v : adj[u]) {
        if (v != parent) {
            leaf = false;
            dfs(v, u, k);
        }
    }
    if (leaf && u != 1) {
        res++;
    }
}

void solve(int n, int m) {
    dfs(1, -1, 0);
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve(n, m);
    return 0;
}