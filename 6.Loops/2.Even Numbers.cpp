//找到1到n里的所有偶数
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n < 2) {
        printf("-1\n");
    } else {
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                printf("%d\n",i);
            }
        }
    }
    return 0;
}