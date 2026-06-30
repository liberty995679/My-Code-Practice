//图的邻接矩阵u k u1... uk
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int kj;
            cin >> kj;
            arr[u - 1][kj - 1] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j];
            if (j < n - 1) {
                cout << ' ';
            }
        }
        cout << '\n';
    }
}