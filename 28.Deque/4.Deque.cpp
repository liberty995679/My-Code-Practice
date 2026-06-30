//输入q 代表q个查询
//0 d x || 1 p || 2 d
//0 代表push 如果d = 0 在开头添加元素 如果d = 1 在末尾添加元素
//1 代表打印元素ap
//2 代表删除 d = 0 删除第一个元素 d = 1 删除最后一个元素
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
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';
void solve() {
    int q;
    cin >> q;
    deque<ll> deq;
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int d, x; cin >> d >> x;
            if (d == 0) deq.push_front(x);
            else deq.push_back(x);
        } else if (t == 1) {
            int p; cin >> p;
            cout << deq[p] << enl;
        } else if (t == 2) {
            int d; cin >> d;
            if (d == 0) deq.pop_front();
            else deq.pop_back();
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