//可以*2或者-1
//n 到 m 最少需要几步
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>   
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const int MOD = 2e5;
int n, m;
vector<int> dist(MOD, -1);
void bfs(int n, int m) {
    queue<int> que;
    que.push(n);
    dist[n] = 0;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        if (u == m) return;
        int v1 = u * 2;
        int v2 = u - 1;
        if (v1 >= 0 && v1 < MOD && dist[v1] == -1) {
            dist[v1] = dist[u] + 1;
            que.push(v1);
        }
        if (v2 < MOD && v2 >= 0 && dist[v2] == -1) {
            dist[v2] = dist[u] + 1;
            que.push(v2);
        }
    }
}

void solve() {
    cin >> n >> m;
    bfs(n, m);
    cout << dist[m] << endl;
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