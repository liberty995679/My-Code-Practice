//白天添加细菌，晚上细菌数量翻倍,倒推添加次数
#include <iostream>

using namespace std;

unsigned int change(unsigned int n) {
    int count = 0;
    while (n > 0) { //循环条件为大于0
        if (n & 1) {  //判断奇偶 ,奇数就添加一次
            count++;
            n >>= 1;
        } else {
            n >>= 1;
        }
    }
    return count;
}    

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    int x;
    cin >> x;
    cout << change(x) << endl;
    return 0;
}