//给四个数
//如果a^b > c^d 输出YES否则NO
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

void calculate(ll a, ll b, ll c, ll d) {  //数据溢出太大,用对数
    if (b * log(a) > d * log(c)) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
}

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    calculate(a, b, c, d);
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