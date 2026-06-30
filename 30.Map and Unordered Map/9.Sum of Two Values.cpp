//输入n个数，找两个不同位置的总和等于x
//输入n ， x
//输入数组a
//输出坐标 从1开始
//无解输出 IMPOSSIBLE
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

void solve() {
    int n, x;
    cin >> n >> x;
    multimap<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int val; cin >> val;
        mp.insert({val, i});  //multimap：用 mp.insert({key, value})
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        int cur = it->first;
        int goal = x - cur;
        auto pos = mp.find(goal);
        if (pos != mp.end()) {
            if (pos->second != it->second) {
                cout << it->second << ' ' << pos->second << enl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << enl;
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