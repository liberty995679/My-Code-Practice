//t个用例
//对每个数字计算阶乘
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
    vector<ll> arr(n + 1);
    arr[0] = 1;
    for (int i = 1; i <= n; i++) {
        arr[i] = (arr[i - 1] * i);
    }
    cout << arr[n] << '\n';
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        calculate(n);
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