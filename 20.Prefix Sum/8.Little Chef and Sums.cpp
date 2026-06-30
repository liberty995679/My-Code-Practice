//前缀和与后缀和,找下标，满足前缀和与后缀和总和最小
#include <iostream>
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
    cin >> t;    //合并前缀和与后缀和，会发现他们有重叠
    while (t--) {  //他们变成了数组总和加a[i]
        int n;      // 所以题目变成了求最小数在的坐标
        cin >> n;
        vector<int> num(n + 1);
        ll total = 0;
        for (int i = 1; i <= n; i++) {
            cin >> num[i];
            total += num[i];
        }
        ll mintotal = total + num[1];
        int index = 1;
        for (int i = 2; i <= n; ++i) {
            ll sum = total + num[i];
            if (sum < mintotal) {
                mintotal = sum;
                index = i;
            }
        }
        cout << index << '\n';
    }
    return 0;
}