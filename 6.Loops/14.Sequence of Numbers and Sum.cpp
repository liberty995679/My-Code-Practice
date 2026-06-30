//输入n,m
//输出包含n和m的从大到小的数
//输出sum=
//可以保证n和m中有一个<=0的数来结束循环
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
    for (int i = a; i <= b; i++) {
        cout << i << ' ';
        sum += i;
    }
    cout << "sum =" << sum << endl;
}

void solve() {
    int n, m;
    while (cin >> n >> m) {
        if (n <= 0 || m <= 0) break;
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