//给三个数
//输出升序后的他们和原读入的顺序
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long;
 
void solve() {
    vector<int> a(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    vector<int> b = a;
    sort(b.begin(), b.end());
    for (int i: b) {
        cout << i << endl;
    }cout << '\n';
    for (int i : a) {
        cout << i << endl;
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