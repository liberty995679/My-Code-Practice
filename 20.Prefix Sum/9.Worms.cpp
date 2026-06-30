//前缀和,找出肥美虫子的位置
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
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        sum[i] = sum[i - 1] + num[i];
    }
    int m;
    cin >> m;
    while (m--) {
        int q;
        cin >> q;     //直接用for循环查找会超时,所以用二分查找
        int idx = lower_bound(sum.begin() + 1, sum.end(), q) - sum.begin(); //输出第一个大于等于q的坐标
        cout << idx << '\n';
    }
    return 0;
}