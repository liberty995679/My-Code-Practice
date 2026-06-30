//给n个数
//数这个数二进制有几个1
//将这些1拼成一个数输出
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
    int k = __builtin_popcount(n);
    int res = (1 << k ) - 1;
    cout << res << endl;
}

void solve() {
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        calculate(a);
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