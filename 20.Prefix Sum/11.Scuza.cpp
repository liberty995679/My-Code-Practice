//前缀和，爬楼梯,输出他最高能跨过的台阶总和
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;    //要求的应该是k >= 台阶最大值
        vector<ll> num(n + 1);
        vector<ll> sum(n + 1, 0);  //台阶高度总和
        vector<ll> maxnum(n + 1, 0); //前缀台阶高度最大值
        for (int i = 1; i <= n; i++) {
            cin >> num[i];
            sum[i] = sum[i - 1] + num[i];
            maxnum[i] = max(maxnum[i - 1], num[i]);
        }
        while (q--) {
            ll k;
            cin >> k;
            int idx = upper_bound(maxnum.begin(), maxnum.end(), k) - maxnum.begin(); 
            cout << sum[idx - 1] << " "; //返回的是第一个大于k的值的坐标，所以要减一
        }cout << '\n';
    }
    return 0;
}