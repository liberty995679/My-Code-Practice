//输入n,k，对n个数进行与或异或运算找到小于k的最大值，没有则为0
#include <iostream>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    int n, k;
    cin >> n >> k;
    int maxyu = 0; int maxhuo = 0; int maxyihuo = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int yu = i & j;
            int huo = i | j;
            int yihuo = i ^ j;
            if (yu < k && yu > maxyu) maxyu = yu;
            if (huo < k && huo > maxhuo) maxhuo = huo;
            if (yihuo < k && yihuo > maxyihuo) maxyihuo = yihuo;
        }
    }
    cout << maxyu << endl;
    cout << maxhuo << endl;
    cout << maxyihuo << endl;
    return 0;
}