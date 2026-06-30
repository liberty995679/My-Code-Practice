//给两个按钮，每按一次会获得相同的硬币，然后数量-1
//给两次按按钮的机会，求最多的硬币数
#include <iostream>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    if (a > b) cout << a + a - 1 << endl;
    else if (b > a)cout << b + b - 1 << endl;
    else cout << a + b << endl;
    return 0;
}