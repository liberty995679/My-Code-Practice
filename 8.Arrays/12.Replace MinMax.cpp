//找到数组里的最大值和最小值
//将两者进行交换
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cmath>
#include <set>
#include <unordered_map>
using namespace std;
using ll = long long;

void change(const vector<int>& a) {
    int n = a.size();
    vector<int> res = a;
    int mxidx = max_element(res.begin(), res.end()) - res.begin();
    int mnidx = min_element(res.begin(), res.end()) - res.begin();
    swap(res[mxidx], res[mnidx]);
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' ';
        cout << res[i];
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i =0; i < n; i++ ) cin >> arr[i];
    change(arr);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}