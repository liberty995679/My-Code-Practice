//通过比较相邻字符串，推导字母间的大小关系，
//再判断这些关系能否组成一个无环图。
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
vector<int> indeg;  //计算入度
vector<char> res;  
void bfs() {
    res.clear();
    queue<char> que;
    for (char i = 'a'; i <= 'z'; i++) {
        if (indeg[i - 'a'] == 0) que.push(i);
    }
    while (!que.empty()) {
        char u = que.front(); que.pop();
        res.push_back(u);
        int w = u - 'a';
        for (int v: g[w]) {
            indeg[v]--;
            if (indeg[v] == 0) que.push((char)(v + 'a'));
        }
    }
    if (res.size() < 26) {
        cout << "Impossible\n";
        return;
    }
    for (char c: res) {
        cout << c;
    }cout << endl;
}

void solve() {
    int n ;
    cin >> n;
    g.assign(26, vector<int>());
    indeg.assign(26, 0);
    vector<string> arr(n); 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int len = min(arr[i].size(), arr[i+1].size());
        int k = 0;
        while (k < len && arr[i][k] == arr[i+1][k]) k++;
        if (k == len) {
            if (arr[i].size() > arr[i+1].size()) {
                cout << "Impossible\n";
                return;
            }
        } else {
            int u = arr[i][k] - 'a';
            int v = arr[i+1][k] - 'a';
            g[u].push_back(v);
            indeg[v]++;
        }
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
