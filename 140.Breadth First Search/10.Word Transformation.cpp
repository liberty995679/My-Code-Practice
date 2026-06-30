//起始单词 → 目标单词
//每次只能 改一个字母（其他字母位置不变）
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
unordered_map<string, int> id;               // 原始节点编号 -> 紧凑索引映射
vector<vector<int>> adj;                  // 邻接表:存储图的边关系
vector<pair<int, int>> edges;             // 边列表:存储所有输入的边
vector<int> dist;                         // dist[i] = 从起点到节点i的最短距离
int n;

int bfs(int a, int b) {
    dist.assign(n, -1);
    queue<int> que;
    que.push(a);
    dist[a] = 0;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        if (u == b) return dist[b];
        for (int v: adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                que.push(v);
            }
            if (v == b) return dist[v];
        }
    }
    return dist[b];
}

bool panduan(const string& a, const string& b) {  //判断是否只相差一个字母
    if (a.size() != b.size()) return false;
    int cnt = 0;
    for (int i =0; i < a.size(); i++) {
        if (a[i] != b[i]) cnt++;
        if (cnt > 1) return false; 
    }
    if (cnt == 1) return true;
    return false;
}

vector<pair<string, string>> construct(const vector<string>& arr) {
    vector<pair<string, string>> res;
    for (int i =0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (panduan(arr[i], arr[j])) {
                res.push_back({arr[i], arr[j]});
            }
        }
    }
    return res;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        id.clear();
        vector<string> arr;
        string s;
        while (cin >> s && s != "*") {
            if (!id.count(s)) {
                int p = id.size();
                id[s] = p;
                arr.push_back(s);
            }
        }
        n = id.size();
        vector<pair<string, string>> ans = construct(arr);
        adj.assign(id.size(), vector<int>());
        dist.assign(id.size(), -1);
        for (auto& i: ans) {
            int a = id[i.first];
            int b = id[i.second];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        string line;
        getline(cin, line);
        while (true) { 
            if (!getline(cin, line) || line.empty()) break;
            stringstream ss(line);
            string x, y;
            ss >> x >> y;
            if (x.empty() || y.empty()) break;
            int a = id[x];
            int b = id[y];
            int result = bfs(a, b);
            cout << x << ' ' << y << ' ' << result << endl;
        }
        if (t > 0) {
            cout << endl;
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