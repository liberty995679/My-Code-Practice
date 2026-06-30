//对每个k=1,2,…,n，计算在k×k棋盘上放置两个不同的骑士,使它们互不攻击的方案数
//两个骑士互换位置视为同一方案,输出 n 个结果。
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;   //就是找2 * 3的矩形

void solve(ll n) {     //在k行找高度为2的矩形有(k-1)种，在k列找宽度为3的矩形有(k-2)种,则有(k-1)*(k-2)个
    for (ll k = 1; k <= n; k++) {
        if (k < 3) cout << k* k * (k*k - 1) / 2 << endl;//相应的，找3 * 2的矩形也是(k-1)*(k-2)个
        else {           //在k*k格子里选2个，即C(k^2, 2)
            ll all_nums = k * k * (k * k - 1) / 2;
            ll attack = 4 * (k - 1) * (k - 2);    //2种矩形，且矩形内A能先手攻击B，B也能先手攻击A, 也是2种，所以*4
            cout << all_nums - attack << endl;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    solve(n);
    return 0;
}