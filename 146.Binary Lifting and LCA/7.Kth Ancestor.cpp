//t个例子
//p个节点，x, y,y是x的父节点，如果y等于0,x为根节点
//q个查询
//0 y x:x节点添加到y节点上
//1 x:删除x节点
//2 x k: 输出x的第k个父节点
//找出任意时刻某一节点的第k个父节点
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

int maxn = 20;
vector<vector<int>> up;
vector<int> alive;
int kth_ancestor(int u, int k) { //找u的第k个祖先
    for (int j = 0; j < maxn; j++) {
        if (k & (1 << j)) {
            u = up[u][j];
            if (u == 0) return 0; //不存在
        }
    }
    return u;
}

void build() {
    for (int j = 1; j < maxn; j++) {
        for (int i = 1; i <= 100000; i++) {
            if (up[i][j - 1]) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        up.assign(100001, vector<int>(maxn, 0));
        alive.assign(100001, 0);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            alive[x] = 1;
            up[x][0] = y;
        }
        build();
        int q;
        cin >> q;
        while (q--) {
            int type;
            cin >> type;
            if (type == 0) {
                int p, x;
                cin >> p >> x;
                alive[x] = 1;
                up[x][0] = p;
                for (int j = 1; j < maxn; j++) {
                    up[x][j] = up[up[x][j - 1]][j - 1];
                }
            } else if (type == 1) {
                int x;
                cin >> x;
                alive[x] = 0;
            } else {
                int x, k;
                cin >> x >> k;
                if (!alive[x]) {
                    cout << 0 << endl;
                    continue;
                }
                int ans = kth_ancestor(x, k);
                if (ans == 0 || !alive[ans]) cout << 0 << endl;
                else cout << ans << endl;
            }
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