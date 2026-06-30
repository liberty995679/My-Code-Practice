//s(a)表示a的数位之和,输入n,m，输出a,b，满足s(a)>=n,s(b)>=n,s(a+b)<=m
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;     //正常输出会超过64位，所以用字符串
    cin >> n >> m;
    if (n > 1) {
        string a(n, '5');
        string b = string(n - 1, '4') + "5";
        cout << a << endl;
        cout << b << endl;
    } else {
        string a(n, '5');
        string b(n, '5');
        cout << a << endl;
        cout << b << endl;
    }
    return 0;
}