//输入两个数组
//判断b数组是不是a数组的排列
//输出yes or no
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#include <climits>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b[x]++;
    }
    for (auto &i: b) {
        if (a[i.first] != i.second) { //或者可以直接比较map,数值是否相等
            cout << "no\n";
            return;
        } 
    }
    cout << "yes\n";
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