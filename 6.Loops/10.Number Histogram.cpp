//输入一个字符
//还有n个数
//每行输出每个数对应数量的字符
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long;
 
void calculate(int n, string s) {
    for (int i = 0; i < n; i++) {
        cout << s;
    } cout << '\n';
}

void solve() {
    string s;
    cin >> s;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        calculate(n, s);
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