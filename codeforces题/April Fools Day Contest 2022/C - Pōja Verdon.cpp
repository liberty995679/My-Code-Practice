//Aenar 有一个由 n 个整数组成的数组 a 。
//题目名字为 Pōja Verdon
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

//Aenar Targaryen是瓦雷利亚的龙主（一个来自《冰与火之歌》的帝国），在瓦雷利亚被毁灭之前，他将家人移居到了维斯特洛。
//pōja在高等瓦雷利亚语中意为‘他们的’，verdon意为‘总和（或根据上下文为数量）’。
//简而言之：打印数组的总和。

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sum += x;
    }
    cout << sum << enl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}