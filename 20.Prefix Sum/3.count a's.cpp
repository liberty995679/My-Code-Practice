//计算字符串中l-r区间能有几个a , l r从1开始
#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

#define DEBUG

void solve(string &s, vector<int> &sums) {
    s = '0' + s;
    for (int i = 1; i < s.size(); ++i) {
        sums[i] = sums[i - 1];
        if (s[i] == 'a') {
            sums[i] += 1;
        }
    } 
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int q;
    cin >> s >> q;
    vector<int> sums(s.size() + 1, 0);
    solve(s, sums);   //前缀和预处理
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << sums[r] - sums[l - 1] << '\n';
    }
    return 0;
}
