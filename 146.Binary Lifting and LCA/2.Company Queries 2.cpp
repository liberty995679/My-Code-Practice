//找a和b的最低共同老板是谁
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <unordered_map>
using namespace std;
using ll = long long;
int maxn = 20;
void lca(int n, int q,const vector<int>& arr) {
    vector<vector<int>> up(n + 1, vector<int> (maxn, -1));
    up[1][0] = -1;
    vector<int> depth(n + 1);
    for (int i = 2; i <= n; i++) {
        up[i][0] = arr[i];
        depth[i] = depth[arr[i]] + 1;
    }
    for (int j = 1; j < maxn; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j - 1] != -1) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }
     while (q--) {
        int a, b;
        cin >> a >> b;
        if (depth[a] > depth[b]) swap(a, b);
        int diff = depth[b] - depth[a];  // 将b提升到与a相同的深度
        for (int j = 0; j < maxn; j++) {
            if (diff & (1 << j)) {
                b = up[b][j];
            }
        }
        if (a == b) {
            cout << a << endl;
            continue;
        }
        for (int j = maxn - 1; j >= 0; j--) {// 同时向上跳，直到父节点相同
            if (up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }
        cout << up[a][0] << endl;
    }
}

void solve() {
    vector<int> arr;
    int n, q;
    cin >> n >> q;
    arr.assign(n + 1, -1);
    for (int i = 2; i <= n; i++) cin >> arr[i];
    lca(n,q,  arr);
   
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