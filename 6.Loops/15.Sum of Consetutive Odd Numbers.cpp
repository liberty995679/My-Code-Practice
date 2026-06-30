//给两个数
//输出不包含这两数在内的奇数的和
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long;
 
void calculate(int n, int m) {
    int a = min(n, m);
    int b = max(n, m);
    int sum = 0;
    for (int i = a + 1; i < b; i++) {
        if (i & 1) sum += i;
    }
    cout << sum << endl;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        calculate(n, m);
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r" ,stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}