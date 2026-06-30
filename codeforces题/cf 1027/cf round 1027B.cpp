//t个用例 输入一个二进制字符串
//si = s(n - i + 1) 的字符对称之为好对
//主角想重新排列字符串中的字符，使得其恰好有k个好对
//判断能否使字符串中的好对数量等于k
//可以则输出YES 否则输出NO
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;

void solve() { 
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt1 = 0; int cnt0 = 0;
    for (char c: s) {
        if (c == '1') cnt1++;
        else cnt0++;
    }
    bool flag = true;
    if (k == 0) {
        if (cnt0 != cnt1) {
            flag = false;
        }
    } else if (k == n / 2) {
        if (cnt0 % 2 != 0 || cnt1 % 2 != 0) {
            flag = false;
        }
    } else {
        int x = n / 2 - k; //不成对的对数
        if (cnt0 < x || cnt1 < x) {
            flag = false;
        }
        if ((cnt0 - x) % 2 != 0 || (cnt1 - x) % 2 != 0) { //成对的数必须是偶数
            flag = false;
        }
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
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