//输入一个年份
//输出另一个比它大的的年份
//而且它的四个数字不同
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

bool convert(int a) {
    unordered_map<int, int> mp;
    while (a) {
        int x = a % 10;
        a /= 10;
        mp[x]++;
    }
    if (mp.size() == 4) {
        return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    for (int i = n + 1; i <= 9999; i++) {
        if (convert(i)) {
            cout << i;
            return;
        }
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