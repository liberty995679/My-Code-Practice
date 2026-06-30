//y - d(y) = x
//d(y) 是 y 的数位之和
//输入x 找y的数量
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
#include <map>
#include <climits>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int sum_dig(int n) {  //可以用二分查找
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int covert(int x) {
    int l = x; int r = x + 100;
    while (l < r) {
        int mid = l + (r - l)/2;
        if (mid - sum_dig(mid) >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

void solve() {   //x <= y <= x + 90
    int x;
    cin >> x;
    int left = covert(x);
    int res = 0;
    for (int i = left; i <= left + 100; i++) {
        if (i - sum_dig(i) == x) res++;
    }
    cout << res << endl;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}