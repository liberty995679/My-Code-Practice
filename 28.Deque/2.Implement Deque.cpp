//在双端队列上执行入队和出队操作
//第一行输入一个整数 T，表示操作次数
//接下来 T 行，每行是以下四种操作之一：
//“push_front x” 或 “push_back x”，或者 “pop_front” 和 “pop_back”
//每当执行“pop_front”或“pop_back”操作时，输出被弹出的元素，换行分隔
//如果双端队列空了，就输出“Empty”。
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
        string s;
        cin >> s;
        if (s == "push_back") {
            ll x; cin >> x;
            deq.push_back(x);
        } else if (s == "push_front") {
            ll x; cin >> x;
            deq.push_front(x);
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