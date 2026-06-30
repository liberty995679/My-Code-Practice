//定义一个数组bi = b1 * 1 + b2 * 2 + .... + bm * m
//给你一个数组，可以对其进行循环移位，整体反转，尾部追加元素
//t个用例和 q个查询
//1代表 循环右移 2 代表反转， 3代表尾部添加
//每次查询都输出一个结果
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
    deque<ll> deq;
    ll res = 0;
    int q, s, k;
    int m = 0;  //次数
    ll sum = 0;  //S(n)
    ll total = 0; //各个元素之和
    bool flag = true;
    cin >> q;
    while (q--) {
        cin >> s;
        if (s == 3) {
            cin >> k;
            m++;
            sum += (k * m);
            total += k;
            if (flag) deq.push_back(k);
            else deq.push_front(k);
        } else if (s == 2) {
            flag = !flag;
            sum = (m + 1) * (total) - sum;  //数组反转
        } else {
            if (flag) {
                ll tail = deq.back(); //取最后一个数
                deq.pop_back();
                deq.push_front(tail); //放到前面
                sum = sum + total - tail * m;
            } else {
                ll tail = deq.front();
                deq.pop_front();
                deq.push_back(tail);
                sum = sum + total - tail * m;
            }
        }
        cout << sum << enl;
    }
}

int main() {
#ifndef ONLINE_JUDGE   
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}