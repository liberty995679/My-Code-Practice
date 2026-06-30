//对n进行翻转
#include <iostream>

using namespace std;

unsigned int change(unsigned int n) {
    unsigned int num = 0;
    for (int i = 0; i < 32; ++i) {
        num <<= 1;  //num向左移空出空间
        if (n & 1) { //如果最低位是1，那就添加
            num |= 1;  //用或运算添加
        }
        n >>= 1; //因为是翻转，n向右移一位
    }
    return num;
}    

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        unsigned int n;
        cin >> n;
        cout << change(n) << endl;
    }
    return 0;
}