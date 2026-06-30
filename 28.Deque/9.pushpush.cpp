//对于一个空的数组b
//对它执行两个操作
//将ai 加入数组b后 将整个数组反转
//输入长度n 输入数组a
//输出所有ai 加入b后的结果
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
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
    int n;
    cin >> n;
    bool flag = true;
    int x;
    deque<int> deq;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (flag) {
            deq.push_back(x);
        } else {
            deq.push_front(x);
        }
        flag = !flag;
    }
    if (flag) {
        for (const auto& it: deq) {
            cout << it << ' ';
        }cout << enl;
    } else {
        while (!deq.empty()) {
            cout << deq.back() << ' ';
            deq.pop_back();
        }cout << enl;
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