//写一个程序来定义并模拟双端队列的操作，实现下面列出的所有方法。
//程序会读取一串命令，并执行相应操作。每执行完一个命令，都要单独打印一行结果。
//支持的命令有：
//push_front  在队列头部添加一个新元素，打印 ok。
//push_back  在队列尾部添加一个新元素，打印 ok。
//pop_front  移除并输出队列头部的元素。
//pop_back  移除并输出队列尾部的元素。
//front 输出队列头部的元素值（不移除）。
//back  输出队列尾部的元素值（不移除）。
//size  打印队列中元素的数量。
//clear  清空队列（移除所有元素），并打印 ok。
//exit  打印 bye 并结束程序。
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
    deque<ll> deq;
    string s;
    while (cin >> s) {
        if (s == "exit") {
            cout << "bye" << enl;
            break;
        }
        if (s == "size") {
            cout << deq.size() << enl;
        }
        if (s == "clear") {
            deq.clear();
            cout << "ok" << enl;
        }
        if (s == "front") {
            cout << deq.front() << enl;
        } 
        if (s == "back") {
            cout << deq.back() << enl;
        }
        if (s == "push_back") {
            ll x; cin >> x;
            deq.push_back(x);
            cout << "ok" << enl;
        } else if (s == "push_front") {
            ll x; cin >> x;
            deq.push_front(x);
            cout << "ok" << enl;
        } else if (s == "pop_front") {
            if (deq.empty()) {
                cout << "Empty" << enl;
                continue;
            }
            ll ans = deq.front();
            deq.pop_front();
            cout << ans << enl;
        } else if (s == "pop_back") {
            if (deq.empty())  {
                cout << "Empty" << enl;
                continue;
            }
            ll ans = deq.back();
            deq.pop_back();
            cout << ans << enl;
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