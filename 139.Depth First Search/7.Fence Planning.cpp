//每头奶牛在不同坐标,需要建立一个长方形的围栏
//至少要围住一组相同叫声的奶牛,输入n个奶牛坐标，m对相同叫声的奶牛
//求满足要求的围栏的最小周长
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
const int MAXIN = 1e5 + 1;
const int INF = 1e9 + 1;
vector<int> adj[MAXIN]; 
vector<pair<int, int>> pos(MAXIN);
vector<bool> visited(MAXIN);
int xmax = 0; int xmin = 1e9 + 1;
int ymax = 0; int ymin = 1e9 + 1;
void dfs(int u) {
    xmax = max(pos[u].first, xmax);
    xmin = min(pos[u].first, xmin);
    ymax = max(pos[u].second, ymax);
    ymin = min(pos[u].second, ymin);
    visited[u] = true;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
freopen("fenceplan.in", "r", stdin);  //USACO传统题环境
freopen("fenceplan.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> pos[i].first >> pos[i].second;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 1e9 + 1;
    for (int i = 1; i <= n; i++) {
        xmax = 0;
        xmin = INF;    //重置全局变量
        ymax = 0;
        ymin = INF;
        if (!visited[i]){
            dfs(i);
            int res = 2 * ((xmax - xmin) + (ymax - ymin));
            ans = min(res, ans);
        }
    }
    cout << ans << endl;
}