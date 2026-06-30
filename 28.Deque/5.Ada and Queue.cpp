//第一行包含1 ≤ Q ≤ 106，查询的数量。每个查询包含以下命令之一
//back - 从后面打印数字，然后擦除它
//front - 从前面打印数字，然后擦除它
//reverse - 颠倒队列中的所有元素
//push_back N - 将元素 N 添加到后面
//toFront N - 将元素 N 放到前面
//所有数字将是 0 ≤ N ≤ 100
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
    string s;
    ll x;
    deque<ll> deq;
    int flag = 1;
    while (q--) {
        cin >> s;
        if (s == "reverse") flag = -flag;
        if (s == "back") {
            if (deq.empty()) {
                cout << "No job for Ada?" << enl;
                continue;
            }
            if (flag == 1) {
                cout << deq.back() << enl;
                deq.pop_back();
            } else {
                cout << deq.front() << enl;
                deq.pop_front();
            }
        } else if (s == "front") {
            if (deq.empty()) {
                cout << "No job for Ada?" << enl;
                continue;
            }
            if (flag == 1) {
                cout << deq.front() << enl;
                deq.pop_front();
            } else {
                cout << deq.back() << enl;
                deq.pop_back();
            }
        } else if (s == "push_back") {
            cin >> x;
            if (flag == 1) deq.push_back(x);
            else deq.push_front(x);
        } else if (s == "toFront") {
            cin >> x;
            if (flag == 1) deq.push_front(x);
            else deq.push_back(x);
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