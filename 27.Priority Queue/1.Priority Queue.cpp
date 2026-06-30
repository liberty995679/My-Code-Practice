//给定对优先队列 S 的多个操作
//每个操作在一行中给出，格式为 "insert k"、"extract" 或 "end"
//输入以 "end" 操作结束
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
    priority_queue<int> pq;
    string s;
    while (cin >> s) {
        if (s == "end") break;
        if (s == "insert") {
            int k; cin >> k;
            pq.push(k);
        }
        if (s == "extract") {
            cout << pq.top() << '\n';
            pq.pop();
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