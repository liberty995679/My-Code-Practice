//将学生分成两组，每组学生互相都不认识
//输入学生数n,友谊数m.对每个学生输出1和2
//如果没有解决方案，输出IMPOSSIBLE
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
void dfs(int u, int t) {
    res[u] = t;
    for (auto v: arr[u]) {
        if (res[v] == 0) {
            dfs(v, 3 - t);
        } 
        if (res[v] == t) flag = true;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for (int i = 1; i <= n;i++) {
        if (res[i] == 0) {
            dfs(i, 1);
        }
    }
    if (!flag) {
        for (int i = 1; i <= n; i++) {
            cout << res[i];
            if (i < n) cout << ' ';
        }cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}