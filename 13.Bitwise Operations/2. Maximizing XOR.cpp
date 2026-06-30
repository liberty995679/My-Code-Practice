//输入l,r ,对l-r区间内的ab进行异或，输出最大值
#include <iostream>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    int l, r;
    cin >> l >> r;
    int max = 0;
    for (int i = l; i <= r; ++i) {
        for (int j = l; j <= r; ++j) {
            int yihuo = i ^ j;
            if (yihuo > max) max = yihuo;
        }
    }
    cout << max << endl;
    return 0;
}