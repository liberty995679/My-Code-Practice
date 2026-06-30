//n个例子
//计算每个数的约数个数
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <stack>
#include <unordered_map>
#include <climits>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        unordered_map<int, int> mp;
        for (int i = 1; i <= sqrt(x); i++) {
            if (x % i == 0) {
                mp[i]++;
                if (x / i != i) mp[x / i]++;
            }
        }
        cout << mp.size() << '\n';
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}