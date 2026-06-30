//t个用例 输入 a x y
//计算点b是否能比a更早到x和y
//b的开始位置可以整条线上
//也就是x y都可以作为开始位置，a不行
//如果可以输出 YES 否则输出NO
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
    int a, x, y;
    cin >> a >> x >> y;
    if (x > y) swap(x, y);
    if (a < x && x < y ) {
        cout << "YES" << enl;
        return;
    }
    if (x < a && a < y) {
        cout << "NO" << enl;
        return;
    } 
    if (x < y && y < a) {
        cout << "YES" << enl;
        return;
    }
    cout << "NO" << enl;
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