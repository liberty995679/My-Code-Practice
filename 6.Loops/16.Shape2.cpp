//给一个n
//输出一个正金字塔
//*号数为 1 3 5 7 这样的
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
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n - 1; j++) cout << ' ';
        for (int j = 0; j < 2 * i + 1; j ++) cout << '*';
        cout << endl;
    }
}

void solve() {
    int n;
    cin >> n;
    calculate(n);
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