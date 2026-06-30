//n个人围成一个圈
//一个人可以顺时针或者逆时针投球
//输出m次投球之后，有可能拿到球的人数
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>   
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
using ll = long long;
void bfs(int n, int m, int x,const vector<pair<int, char>> &a, set<int> &s) {
    set<int> cur;
    cur.insert(x);
    for (auto& i: a) {
        int r = i.first;
        char c = i.second;
        set<int> xiayige;
        for (int p: cur) {
            if (c == '0' || c == '?') {
                int next = (p + r - 1) % n + 1;
                xiayige.insert(next);
            }
            if (c == '1' || c == '?') {
                int next = (p - 1 - r + n) % n + 1;
                xiayige.insert(next);
            }
        }
        cur = xiayige;
    }
    s = cur;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;
        vector<pair<int, char>> arr;
        while (m--) {
            int r; char c;
            cin >> r >> c;
            arr.push_back({r, c}); 
        }
        set<int> res;
        bfs(n, m, x, arr, res);
        cout << res.size() << endl;
        for (auto& i: res) {
            cout << i << ' ';
        }cout << endl;
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