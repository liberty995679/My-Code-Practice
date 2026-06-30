//计算1到n的素数和
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
 
int is_prime(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    int num = sqrt(n);
    for (int i = 2; i <= num; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (is_prime(i) == 1) cout << i << ' ';
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