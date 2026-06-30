//现在有一个空队列
//t个命令 1 n 代表入队， 2 出队 3 输出队首
//如果队列空了，输出Empty!
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;

void solve() {
    queue<int> q;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            int n; cin >> n;
            q.push(n);
        } else if (x == 2) {
            if (!q.empty()) q.pop();
        } else {
            if (!q.empty()) {
                cout << q.front() << '\n'; //数据量很大所以用'\n'
            } else {
                cout << "Empty!\n";
            }
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