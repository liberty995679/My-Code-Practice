//对输入的数进行+1或者*2 mod 32768
//输出多少次操作后可以归零
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>   
#include <map>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;
const int MOD = 32768; 
int n;
vector<int> dist(MOD, -1);
void bfs(int x) {
    queue<int> que;
    x = x % MOD;
    que.push(x);
    dist[x] = 0;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        int v1 = (u - 1 + MOD) % MOD;
        int v2 = (u + MOD)/ 2;
        if (dist[v1] == -1) {
            dist[v1] = dist[u] + 1;
            que.push(v1);
        }
        if (u % 2 == 0) {
            int v3 = u / 2;
            if (dist[v3] == -1) {
                dist[v3] = dist[u] + 1;
                que.push(v3);
            }
        }
        if (dist[v2] == -1) {
            dist[v2] = dist[u] + 1;
            que.push(v2);
        } 
    }
}

void solve() {
    cin >> n;
    bfs(0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cout << dist[a % MOD] << ' ';
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