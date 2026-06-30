//自定义函数求出两个数字的最大公约数
#include <iostream>

using namespace std;

int gcd(int a, int b) { //欧几里得算法，辗转相除法
    while (a % b) {   //取余数运算，非零值视为true
        int tmp = b;   
        b = a % b;    //gcd(b, a % b) 
        a = tmp;    // 当后者为0, 则b是最大公约数
    }return b;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}