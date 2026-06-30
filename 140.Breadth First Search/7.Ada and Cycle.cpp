//最短环问题
//从 i 出发，沿着有向边走
//最终回到 i 的最短路径长度（最小环长度）
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>   
#include <map>
#include <set>
using namespace std;
using ll = long long; 
vector<vector<int>> g;                    // 地图:存储每个格子的状态('.' 空地, '*' 障碍, 'X' 起点)
vector<int> dis;                   // dis[i][j] = 从起点到(i,j)的最短距离
vector<int> vis;
int dx[4] = {1, 0, 0, -1};                 // 四个方向的x偏移:下、左、右、上
int dy[4] = {0, -1, 1, 0};                 // 四个方向的y偏移:下、左、右、上
int n;
void solve() {
    cin >> n;
    g.assign(n, {});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 1) g[i].push_back(j);
        }
    }
    for (int start = 0; start < n; start++) {
        int mincycle = 1e9;
        for (int j : g[start]) {
            if (j == start) {
                mincycle = 1;  // 找到自环
                break;
            }
        }
        if (mincycle == 1e9 && !g[start].empty()) {
            dis.assign(n, -1);
            queue<int> que;
            for (int j : g[start]) {
                que.push(j);
                dis[j] = 1;
            }
            while (!que.empty()) {
                int u = que.front();
                que.pop();
                for (int v: g[u]) {
                    if (v == start) {
                        mincycle = min(mincycle, dis[u] + 1);
                        goto done;
                    }
                    if (dis[v] == -1) {
                        que.push(v);
                        dis[v] = dis[u] + 1;
                    }
                }
            }  
            done:;
        }
        if (mincycle == 1e9) {
            cout << "NO WAY" << endl;
        } else {
            cout << mincycle << endl;
        }
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