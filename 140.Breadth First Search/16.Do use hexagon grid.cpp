//无限六边形方格
//判断有几个连通分量
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
int dx[6] = {-1, -1, 0, 0, 1, 1};
int dy[6] = {-1, 0, -1, 1, 0, 1};

struct Hash {
    size_t operator()(const pair<int,int>& p) const {
        return ((size_t)p.first << 32) ^ (size_t)p.second;
    }
};

unordered_map<pair<int,int>, int, Hash> mp;
unordered_map<pair<int,int>, bool, Hash> vis;

int bfs() {
    queue<pair<int, int>> que;
    int res = 0;
    for (auto& k: mp) {
        auto i = k.first;
        if (!vis[i]) {
            que.push(i);
            vis[i] = true;
            res++;
        }
        while (!que.empty()) {
            auto head = que.front();
            que.pop();
            int u = head.first;
            int v = head.second;
            for (int i = 0; i < 6; i++) {
                int u1 = u + dx[i];
                int v1 = v + dy[i];
                if (mp.count({u1, v1}) && !vis[{u1, v1}]) {
                    vis[{u1, v1}] = true;
                    que.push({u1, v1});
                }
            }
        }
    }return res;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    for (auto& i: arr) {
        mp[i] = 1;
    }
    cout << bfs() << endl;
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