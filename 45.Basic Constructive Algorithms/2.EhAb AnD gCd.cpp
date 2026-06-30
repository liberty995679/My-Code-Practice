//构造函数，已知gcd(a,b) + lcm(a,b) = x,输入x，求a, b
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void solve(int x) {
    int g = 1;
    for (int i = 2; i * i <= x; i++) { //找除它本身以外的最大真约数
        if (x % i == 0) {
            int g1 = x / i;   //i 和 x/i 都是x的约数
            if (i < x) g = max(g, i);
            if (g1 < x) g = max(g1, g);
        }                               //找一个互质对(u, v) = (1, k) ,它们gcd都是1
    }                                 //令a=g*u,b=g*v,k=u*v=x/g-1,因为uv的gcd等于1,所以可以使它们其中一个为1
    cout << g << ' ' << x - g << endl;  //a = g * 1, b = g*(k), 即g*(x/g-1)当u=1,则a=g, b=x-g
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
        int x;
        cin >> x;
        solve(x);
    }
    return 0;
}