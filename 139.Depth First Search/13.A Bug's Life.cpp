//输入场景数量t,每个场景有n个昆虫,和m个交互
//输出 Scenario #i:
//后面有一行表示 No suspicious bugs found! 如果实验符合他对虫子性行为的假设，
//或者 Suspicious bugs found! 如果霍普教授的假设绝对错误。
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int MAXIN = 2e5 + 1;   
vector<int> arr[MAXIN];
vector<bool> visited(MAXIN);
vector<int> res(MAXIN, 0);
bool flag = false;

void dfs(int u, int c) {
 
    res[u] = c;
    for (auto v: arr[u]) {
        if (flag) return;
        if (res[v] == 0) dfs(v, 3 - c);
        if (res[v] == c) flag = true;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            arr[i].clear();
            res[i] = 0;
        }
        flag = false;
        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        for (int j = 1; j <= n; j++) {
            if (res[j] == 0) dfs(j, 1);
        }
        cout << "Scenario #" << i << ':' << endl;
        if (!flag) cout << "No suspicious bugs found!" << endl;
        else cout << "Suspicious bugs found!" << endl;
    }
    return 0;
}