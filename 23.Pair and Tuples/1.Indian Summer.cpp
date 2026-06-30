//n个用例 每个用例都有两个字符串
//计算有多少个不同的树叶
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
#include <set>
using namespace std;
using ll = long long;

void solve() { 
    int n;
    cin >> n;
    set<string> s;
    string aa;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, aa);
        s.insert(aa);
    }
    cout << s.size() << endl;
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