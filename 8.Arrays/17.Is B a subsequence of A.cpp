//判断b是不是a的子序列(连续的)
//输入n，m
//输入n个数的数组a和m个数的数组b
//输出yes or no
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cmath>
#include <set>
#include <unordered_map>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    bool flag = true;
    vector<int> c(m); //c标记是否已经存在
    int j = 0;   //写外面
    for (int i = 0; i < n; i++) {
        if (b[j] == a[i]) {
            c[j] = 1;
            j++;
        }
    }
    for (int i = 0; i < m; i++) {
        if (c[i] == 0) {
            flag = false;
            break;
        }
    }
    if (!flag) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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