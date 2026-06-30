//构造字符串，在n长度的字符串，每个长度为a的子串中都有b个不同的字母
#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

string solve(int n, int a, int b) {
    string s;
    for (int i = 0; i < b; i++) { //准备b个不同字符拼接
        s += char('a' + i);  //从a开始加字符
    }
    for (int i = b; i < a; i++) { //a-b区间内剩下的相同字符
        s += "a";
    }
    string ans;
    while (ans.size() < n) {   //将a字符串循环拼接
        ans += s;
    }
    if (ans.size() > n) ans.resize(n);
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        cout << solve(n, a, b) << endl;
    }
    return 0;
}