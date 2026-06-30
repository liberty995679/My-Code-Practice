//前缀和，石头价值,如果type为2，就对他排序再选
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
    int n;
    cin >> n;
    vector<int> num(n + 1);
    vector<ll> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {  //原数组前缀和
        cin >> num[i];
        sum[i] = sum[i - 1] + num[i];
    }
    vector<ll> sum1(n + 1, 0);
    sort(num.begin(), num.end());
    for (int i = 1; i <= n; i++) {  //排序后的前缀和
        sum1[i] = sum1[i - 1] + num[i];
    }
    int m;
    cin >> m;
    while (m--){
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) cout << sum[r] - sum[l - 1] << '\n';
        else  cout << sum1[r] - sum1[l - 1] << '\n';
    }
    return 0;
}
