//计算列表里不同值的数量
//输入n 输入数组a
//输出结果
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
    set<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(x);
    }
    cout << s.size() << enl;
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