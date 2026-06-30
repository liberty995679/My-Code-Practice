//根据输入的字符串进行拓扑排序
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;
vector<vector<int>> g;
unordered_map<char, int> indeg;
vector<char> res;

void bfs() {
    res.clear();
    queue<char> que; 
    for (char i = 'A'; i <= 'Z'; i++) {
        if (indeg.count(i) && indeg[i] == 0) que.push(i);
    }
    while (!que.empty()) {
        char c = que.front(); que.pop();
        res.push_back(c);
        int u = c - 'A';
        for (int v: g[u]) {
            char vv = (char)(v + 'A');
            indeg[vv]--;
            if (indeg[vv] == 0) que.push(vv);
        }
    }
    for (char c: res) {
        cout << c;
    }cout << endl;
}

void solve() {
    string s;
    vector<string> arr;
    while (cin >> s) {
        if (s == "#") break;
        arr.push_back(s);
    }
    g.assign(60, vector<int>());
    for (int i = 0; i < arr.size() - 1; i++) {
        string a = arr[i];
        string b = arr[i + 1];
        int len = min(a.size(), b.size());
        int k = 0;
        while (k < len && a[k] == b[k]) k++;
        if (k == len) continue;
        g[a[k] - 'A'].push_back(b[k] - 'A');
        if (!indeg.count(a[k])) indeg[a[k]] = 0;
        indeg[b[k]]++;
    }
    bfs();
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
