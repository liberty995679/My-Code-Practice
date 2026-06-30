//你有一个初始为空的整数数组 A
//q次查询
//push 
//x ：将数值 x 添加到 A 的末尾
//pop ：移除 A 中最小的数字
//top ：输出 A 中最小的数字
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
    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (q--) {
        string s;
        cin >> s;
        if (s == "push") {
            int x;
            cin >> x;
            pq.push(x);
        } else if (s == "top") {
            int it = pq.top();
            cout << it << '\n';
        } else {
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