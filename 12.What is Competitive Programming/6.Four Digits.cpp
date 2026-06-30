//对输入的数字，转换成四位，空的用0不全
#include <iostream>
#include <string>
using namespace std;

string solve(string a) {
    if (a.size() == 4) return a;
    a = '0' + a;
    return solve(a);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}