//前缀和,输入格子带，有黑白色，如果存在长度为k的黑色格子带输出0,没有则输出最少的差值
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<char> letter(n + 1);
        vector<int> sum(n + 1, 0);  //保存前缀和
        for (int i = 1; i <= n; i++) {
            cin >> letter[i];
            sum[i] = sum[i - 1] + (letter[i] == 'B');
        }
        int maxnum = 0;
        for (int l = 1, r = k; r <= n; l++, r++) {
            maxnum = max(maxnum, sum[r] - sum[l - 1]);
        }
        cout << k - maxnum << endl;
    }
    return 0;
}