//给一个数学表达式
//计算它的结果
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>
#include <unordered_map>
using namespace std;
using ll = long long;
 
int calculate(int a, int b, char x) {
    if (x == '+') return a + b;
    else if (x == '-') return a - b;
    else if (x == '*') return a * b;
    return a / b;
}

void solve() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    int a, c, ans;
    char b, d;
    ss >> a >> b >> c >> d >> ans;
    int res = calculate(a, c, b);
    if (res == ans) cout << "Yes" << '\n';
    else cout << res << endl;
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