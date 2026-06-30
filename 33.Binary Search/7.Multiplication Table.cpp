//乘法表格，二分查找排序后中间的值
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll search_num(ll m, ll n) {    //计算小于等于m的数量
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += min(m / i, n);
    }
    return cnt;
}
 
ll solve (ll n) {  //找大于等于中间元素的值
    ll x = n * n / 2 + 1;  //中间元素的位置
    ll l = 1; ll r = n * n;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        ll cnt = search_num(mid, n);
        if (cnt >= x) r = mid;   
        else l = mid + 1;
    }
    return l;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}