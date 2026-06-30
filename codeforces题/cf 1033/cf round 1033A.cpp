//t个用例 输入三个矩形的长和宽
//判断他们是否能组成一个正方形
//不能翻转
//如果可以，输出Yes 否则输出No
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
    int l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    if (l1 == l2 && l2 == l3) {
        if (b1 + b2 + b3 == l1) {
            cout << "Yes" << enl;
            return;
        }
    }
    if (b1 == b2 && b2 == b3) {
        if (l1 + l2 + l3 == b1) {
            cout << "Yes" << enl;
            return;
        }
    }
    int lmx = max({l1, l2, l3});
    int bmx = max({b1, b2, b3});
    if (lmx > bmx) {
        if (b1 + b2 == lmx && b1 + b3 == lmx && l2 + l3 == lmx) {
            cout << "Yes" << enl;
            return;
        }
    } else {
        if (l1 + l2 == bmx && l1 + l3 == bmx && b2 + b3 == bmx) {
            cout << "Yes" << enl;
            return;
        }
    }
    cout << "No" << enl;
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