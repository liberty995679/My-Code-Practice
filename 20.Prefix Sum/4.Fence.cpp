//移除篱笆前面的木板，以便于钢琴搬运过去
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
    string s;
    int n, k;
    cin >> n >> k;
    vector<int> num(n + 1);
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        sum[i] = sum[i - 1] + num[i];
    }
    int mini = sum[k] - sum[0];  //算1到k的总和假定为最小
    int p = 1;  //p来定位最小的坐标
    for (int l = 1, r = k; l <= n - k + 1; ++l) {
        int x = sum[r] - sum[l - 1];
        if (x < mini) {
            mini = x;
            p = l;
        }
        r++;
    }
     cout << p << endl;
    return 0;
}
