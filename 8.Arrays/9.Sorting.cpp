//判断输入的数进行排序
//冒泡或者选择
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;
using ll = long long;

void sort111(const vector<int>& s) {
    vector<int> a = s;
    int n = a.size();
    for (int i = 0; i < n - 1; i++) { //最后一个元素无需排序
        int p =i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[p]) {
                p = j;       
            }
        }
        if (p != i) {
            int tmp = a[i];
            a[i] = a[p];
            a[p] = tmp;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' ';
        cout << a[i];
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort111(arr);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}