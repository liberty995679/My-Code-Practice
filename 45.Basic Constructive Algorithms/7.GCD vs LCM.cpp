//a+b+c+d = n, gcd(a,b) = lcm(c,d),输入n，求abcd
#include <iostream>
#include <vector>

using namespace std;

void solve(int n) {  //令lcm(c,d)=1,gcd(1, n-3)，满足a+b+c+d = n
    int a = 1;
    int b = n - 3;
    int c = 1;
    int d = 1;
    if (b >= 1 && n >= 4) {
        cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    }
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
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}