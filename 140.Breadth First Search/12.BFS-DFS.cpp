//给定遍历序列 → 构造图
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
int n;
void solve() {
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    vector<int> bfs(n);
    vector<int> dfs(n);
    for (int i = 0; i < n; i++) {
        cin >> bfs[i];
    }for (int i = 0; i < n; i++) cin >> dfs[i];
    if (bfs[1] != dfs[1]) {
        cout << -1 << endl;
        return;
    }
    cout << 2 * (n - 1) - 1 << endl;
    for (int i = 1; i < n; i++) {
        cout << dfs[i - 1] << ' ' << dfs[i] << endl;
    }
     for (int i =2 ; i < n; i++) {
        cout << 1 << ' ' << bfs[i] << endl;
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