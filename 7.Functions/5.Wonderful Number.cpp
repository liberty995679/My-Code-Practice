//判断一个数是否为好数
//两个前提，奇数和其二进制是回文
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long;
 
bool calculate(int n) {
    if (n == 1 || n == 0) return true;
    string res;
    while (n > 0) {
        res += (n % 2) ? '0' : '1';
        n /= 2;
    }
    string a = res;
    reverse(a.begin(), a.end());
    return a == res;
}

void solve() {
    int n;
    cin >> n;
    if (calculate(n) && n % 2 == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
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