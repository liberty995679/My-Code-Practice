//有 n 张音乐会门票，每张票有一个价格。
//然后有 m 位顾客依次到达。
//每位顾客会宣布他们愿意支付的最高价格，之后他们会得到一张门票，这张票的价格不超过该最高价，并且是不超过最高价的最大可能价格（即最接近最高价但不超过它）。
//如果有多张票价格相同且都符合条件，可以任意选其中一张。
//输入格式​
//第一行包含两个整数 n 和 m，分别是门票数量和顾客数量。
//第二行包含 n 个整数 h1, h2, ..., hn，是每张票的价格。
//第三行包含 m 个整数 t1, t2, ..., tm，是每位顾客愿意支付的最高价格，按他们到达的顺序给出。
//输出格式​
//对于每位顾客，输出他们最终支付的票价，然后这张票就不能再被购买。
//如果顾客无法得到任何票（即没有票价不超过他的预算），输出 -1。
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
    int n, m;
    cin >> n >> m;
    multiset<int> s;  //允许重复票价
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        auto it = s.lower_bound(x);
        if (it != s.end()) {
            if (*it == x) {
                cout << *it;
                s.erase(it);
            } else {
                if (it != s.begin()) {
                    it = prev(it);
                    cout << *it;
                    s.erase(it);
                } else { //已经是开头了
                    cout << -1;
                }
            }
        } else {
            if (s.empty()) {
                cout << -1 << enl;
                continue;
            } 
            it = prev(it);
            cout << *it;
            s.erase(it);
        }
        cout << enl;
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