//找x的k个上级
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
    for (int i = 2; i <= n; i++) {
        up[i][0] = arr[i];
    }
    for (int j = 1; j < maxn; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j - 1] != -1) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }
     while (q--) {
        int x, k;
        cin >> x >> k;
        // 通过二进制分解 k，跳跃到第 k 级祖先
        for (int j = 0; j < maxn; j++) {
            if (k & (1 << j)) { // 如果 k 的第 j 位是 1
                x = up[x][j];
                if (x == -1) break; // 已经超出树的范围
            }
        }
        cout << x << "\n";
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