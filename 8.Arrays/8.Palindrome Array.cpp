//判断输入的n个数组成的数组是否是回文
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;
using ll = long long;

bool huiwen(const vector<int>& s) {
    vector<int> a = s;
    reverse(a.begin(), a.end());
    return a == s;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    if (huiwen(arr)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}