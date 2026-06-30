//A从顶点1开始移动，B从顶点x开始移动，B优先移动
//A要追上B,则与B站在同一顶点
//他们能走的路构成一棵树，输出他们总步数的最大值
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int MAXIN = 2e5 + 1;   //找到一个节点使得它距离A最远或者距离B最近
vector<int> arr[MAXIN];
vector<bool> visited(MAXIN);
int distA[MAXIN]; int distB[MAXIN];
void dfs(int u, int parent, int depth, int dist[]) {  //用 DFS 求树上每个节点的深度
    dist[u] = depth;   
    for (auto v: arr[u]) {
        if (v != parent) {
            dfs(v, u, depth + 1, dist);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(1, -1, 0, distA);
    dfs(x, -1, 0, distB);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (distA[i] > distB[i]) {
            ans = max(ans, distA[i]);
        }
    }
    cout << ans * 2 << endl;  //因为A要追上B,A走的同时，B也在走,求的是总步数
    return 0;
}