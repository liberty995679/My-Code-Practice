//构造字符串,尽可能把R均匀地分散到B中间,让R不会连续太多
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, r, b;
        cin >> n >> r >> b;
        int k = r / (b + 1);   //每段至少有k个R
        int w = r % (b + 1);   //前面W段再加一个R
        string ans = "";
        while (ans.size() < n) {
            if (w > 0) {
                ans += 'R';
                w--;
            }
            for (int i = 0; i < k; i++) {
                ans += 'R';
            }
            ans += 'B';
        }
        ans = ans.substr(0,ans.size() - 1);
        cout << ans << endl;
    }
}