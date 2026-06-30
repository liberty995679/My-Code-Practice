//集合(set)是C++标准模板库(STL)的一部分
//1 x：将元素  添加到集合中。
//2 x：从集合中删除元素  （如果数字  不在集合中，则不执行任何操作）。
//3 x：如果数字  在集合中，则打印"Yes"（不带引号），否则打印"No"（不带引号）。
//输入q 表示q个查询
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
    int q;
    cin >> q;
    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            s.insert(x);
        } else if (t == 2) {
            if (s.count(x)) s.erase(x);
        } else {
            if (s.count(x)) {
                cout << "Yes" << enl;
            } else {
                cout << "No" << enl;
            }
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