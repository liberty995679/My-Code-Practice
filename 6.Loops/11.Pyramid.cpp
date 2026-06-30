//输入n
//输出金字塔左边的
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long;
 
void calculate(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << '*';
        }
        cout << '\n';
    } 
}

void solve() {
    int n;
    cin >> n;
    calculate(n);
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