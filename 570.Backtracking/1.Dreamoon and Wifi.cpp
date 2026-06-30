//两组字符串，正确路线，不确定路线
//判断不确定路线达到正确的概率
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;
using ll = long long;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int anspos = 0;
    for (int i = 0; i < s1.size(); i++) {
        anspos += (s1[i] == '+' ? 1 : -1);
    }
    int moves = 0;
    int nowpos = 0;
    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] != '?') {
            nowpos += (s2[i] == '+' ? 1 : -1);
        }
        else moves++;
    }
    int dist = anspos - nowpos;
    double res = 0;
    if ((dist + moves) % 2 != 0 || moves < abs(dist)) {
        res = 0;
    } else {
        int m = (moves + abs(dist)) / 2;
        int c = 1;
        for (int i = 0; i < m; i++) {
            c *= moves - i;
        }
        for (int i = 1; i <= m; i++) {
            c /= i;
        }
        res = (double)c / (1 << moves);
    }
    cout << fixed << setprecision(10);
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}