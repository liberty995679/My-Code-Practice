//现在，你要扮演“安静者”的角色，解决这个问题。
//记录所有暗号，回答老师的问题。（老师可能会问同一个问题多次）
//注意：同一个女生可以有多个暗号。如果同一个暗号对应多个女生，最新记录的女生才是正确答案。
//n代表暗号数量 每行有两个整数和一个女生的名字
//然后是t个查询,两个整数的查询
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
#include <unordered_set>
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
    int n;
    cin >> n;
    map<pair<int, int>, string> mp;
    for (int i = 0; i < n; i++) {
        int x, y; string s;
        cin >> x >> y >> s;
        mp[{x, y}] = s;
    }
    int t; cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        cout << mp[{x, y}] << enl;
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