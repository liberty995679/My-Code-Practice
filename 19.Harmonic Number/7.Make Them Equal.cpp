//输出最少操作次数，能将字符串变成指定单个字母组成的字符串
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void solve(int n, char c, string s) {
    bool flag = true;
    for (char ch : s) {
        if (ch != c) {
            flag = false; //判断s里的字符是不是都等于c
            break;
        }
    }
    if (flag) {  //如果全部相等，则输出0
        cout << 0 << endl;
    } else {   //不相等
        bool judge = false;  //判断是否一次操作可以完成
        int x = -1;
        for (int i = 1; i <= n; ++i) {
            bool y = true;
            for (int j = i; j<= n; j += i) {
                if (s[j - 1] != c) {   //j是1开头,下标减一才是位置
                    y = false;  //如果有一个i的倍数不是c
                    break;
                }
            }
            if (y) {    //x记录
                x = i;  //找到一个i的倍数全是c
                judge = true;
                break;
            }
        }
        if (judge) cout << 1 << '\n' << x << '\n';
        else cout << 2 << '\n' << n << ' ' << n - 1 << '\n';
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r",  stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        char c;
        string s;
        cin >> n >> c >> s;
        solve(n, c, s);
    }
    
}