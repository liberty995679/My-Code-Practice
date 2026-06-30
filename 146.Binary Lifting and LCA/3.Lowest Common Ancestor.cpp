//输出u和v的最近公共祖先
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, q;
int maxn = 20;

void lca(const vector<int> &arr) {
    vector<vector<int>> up(n + 1, vector<int>(maxn, -1));
    vector<int> depth(n + 1);
    up[0][0] = -1;
    for (int i = 1; i < n; i++) {
        up[i][0] = arr[i];
        depth[i] = depth[arr[i]] + 1;
    }
    for (int j = 1; j < maxn; j++) {
        for (int i = 0; i < n; i++) {
            if (up[i][j -1] != -1) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            } else up[i][j] = -1;
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (depth[u] > depth[v]) swap(u, v);
        int diff = depth[v] - depth[u];
        for (int j = 0; j < maxn; j++) {
            if (diff & (1 << j)) {
                v = up[v][j];
                if (v == -1) break;
            }
        }
        if (u == v) {
            cout << u << endl;
            continue;
        }
        for (int j = maxn - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        cout << up[u][0] << endl;
    }
}

void solve() {
    cin >> n >> q;
    vector<int> arr(n + 1, -1);
    for (int i = 1; i < n; i++) cin >> arr[i];
    lca(arr);
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