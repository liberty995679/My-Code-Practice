//输入n,k，取1-n范围内的数进行与运算，输出小于k的最大数
#include <iostream>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int max = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (max < (i & j)) {
                    if ((i & j) < k) {
                        max = i & j;
                    }
                }
            }
        }
        cout << max << endl;
    }
    return 0;
}