//对n的临近比特位进行交换
#include <iostream>

using namespace std;

int change(int n) {
    int evenbit = n & 0x55555555; //偶数位掩码,32位
    int oddbit = n & 0xAAAAAAAA; //奇数位掩码
    return (evenbit << 1) | (oddbit >> 1);  
}    //偶数位向左移，奇数位向右移，实现交换

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << change(n) << endl;
    }
    return 0;
}