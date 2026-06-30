//给一个n个数
//输出它的每一位数，从左往右输出从个位开始
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
    if (n == 0) {  //要考虑0的情况
        cout << "0 "; 
        cout << '\n';
        return;
    }
    while (n > 0) {
        int x = n % 10;
        cout << x << ' ';
        n /= 10;
    }cout << '\n';
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