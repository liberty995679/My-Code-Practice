//邮票寄信,每个邮票都有两个城市的路线
//输出两条可能的路线中的其中一条
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
const int MAXIN = 1e9 + 1;
map<int, vector<int>> arr;
map<int, bool> visited;
vector<int> res;
void dfs(int u) {
    visited[u] = true;
    res.push_back(u);
    for (auto &v : arr[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void solve(int head) {
    dfs(head);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mp[a]++;mp[b]++;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    int head = -1;
    for (auto i = mp.begin();i != mp.end(); i++) {
        if (i->second == 1) {
            head = i->first;
            break;
        }
    }
    if (head != -1) solve(head);
    for (int i = 0; i <= n; i++) {
        cout << res[i];
        if (i != n) cout << ' ';
    }cout << endl;
    return 0;
}