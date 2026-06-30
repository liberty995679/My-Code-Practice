//自定义函数floor，ceil，round
#include <iostream>

using namespace std;

int floor(int a, int b) {
    return a / b;
}

int ceil(int a, int b) {
    return (a % b == 0) ? (a / b) : (a / b + 1);
}

int round(int a, int b) {
    double num = (double)a / (double)b;
    int num1 = a / b;
    double xiaoshu = num - (double)num1;
    if (xiaoshu >= 0.5) return num1 + 1;
    else return num1;
}

int main() {
    int a, b;
    cin >> a >> b;
    printf("floor %d / %d = %d\n", a, b, floor(a, b));
    printf("ceil %d / %d = %d\n", a, b, ceil(a, b));
    printf("round %d / %d = %d\n", a, b, round(a, b));
    return 0;
}