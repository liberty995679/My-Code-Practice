//计算1到n的数位总和在a和b(包含)之内的总和
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
using namespace std;
using ll = long long;
 
bool found(int n, int a, int b) {
    int sum = 0;
    while (n > 0) {
        int x = n % 10;
        sum += x;
        if (sum > b) return false;
        n /= 10;
    }
    if (sum < a) return false;
    return true;
}

void calculate(int n, int a, int b) {
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        if (found(i, a, b)) res += i;
    }
    cout << res << endl;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    calculate(n,a, b);
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