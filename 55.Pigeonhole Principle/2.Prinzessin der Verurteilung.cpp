//找字符串中未出现的最短子串，按照字典顺序来
//a-z, aa-az,ba-bz...
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

void solve(int n, string s) {  //26^3 = 17576 > n 所以子串长度最多为3
    for (char i = 'a'; i <= 'z'; i++) {
        if (s.find(i) == s.npos) {
            cout << i << endl;
            return;
        }
    }    //暴力
    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            string ans = "";  //ans = ans + i + j会变成int计算
            ans.push_back(i);
            ans.push_back(j);
            if (s.find(ans) == s.npos) {
                cout << ans << endl;
                return;
            }
        }
    }
    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            for (char m = 'a'; m <= 'z'; m++) {
                string ans = "";
                ans.push_back(i);ans.push_back(j);
                ans.push_back(m);
                if (s.find(ans) == s.npos) {
                    cout << ans << endl;
                    return;
                }
            }
        }
    }

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
        int n; string s;
        cin >> n >> s;
        solve(n, s);
    }
}