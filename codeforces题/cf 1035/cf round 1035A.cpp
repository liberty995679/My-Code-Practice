//t个用例 让a变成b
//第一种操作 a = a + 1 花费x
//第二种操作 a = a ^ 1 花费y
//计算让a变成b的最小花费
//如果无解输出-1
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

void solve(){
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a > b) {
        if ((a ^ 1) == b) {
            cout << y << enl;
            return;
        } else {
            cout << -1 << enl;
            return;
        }
    }
    if (a == b) {
        cout << 0 << enl;
        return;
    }
    ll k1 = b - a;
    ll cost1 = x * k1;
    ll k2 = (b + 1) / 2 - (a + 1) / 2;
    ll cost2 = y * k2 + (k1 - k2) * x; //总共需要前进的次数
    cout << min(cost1, cost2) << enl; 
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