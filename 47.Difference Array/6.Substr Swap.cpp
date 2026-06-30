//两个字符串ST，在l,r区间进行互相交换,再输出最终结果
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int N  = 5e5 + 3;
vector<int> diff(N, 0);

void solve( int  l, int r) {
    diff[l]++;
    diff[r + 1]--;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    while (m--) {
        int l, r;
        cin >> l >> r;
        solve( l, r);
    }
    vector<int> nums(n + 2);
    for (int i = 1 ; i <= n + 1; i++) {
        nums[i] = diff[i] + nums[i - 1];
    }
    for (int i = 1; i <= n ; i++ ) {
        if (nums[i] & 1) swap(s[i - 1], t[i- 1]);
    }
    cout << s;
    return 0;
}