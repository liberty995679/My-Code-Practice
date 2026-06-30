//找a和b当中的幸运数字,包含a和b
//幸运数字只包含4或者7
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
 
bool found(int n) {
    while (n > 0) {
        int x = n % 10;
        if (x != 4 && x != 7) return false;
        n /= 10;
    }
    return true;
}

void calculate(int a, int b) {
    int x = min(a, b);
    int y = max(a, b);
    vector<int> arr;
    for (int i = x; i <= y; i++) {
        if (found(i)) arr.push_back(i);
    }
    if (arr.size() == 0) cout << -1 << '\n';
    else {
        for (int i : arr) {
            cout << i << ' ';
        }
    }
}

void solve() {
    int a, b;
    cin >> a >> b;
    calculate(a, b);
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