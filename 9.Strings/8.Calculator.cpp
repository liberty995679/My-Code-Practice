//对输入的字符串进行数学计算
#include <iostream>
#include <string>

using namespace std;

int jisuan(int a, char s, int b) {
    int n = 0;
    switch(s) {
        case '+': n = a + b;
        break;
        case '-': n = a - b;
        break;
        case '*': n = a * b;
        break;
        case '/': n = a / b;
        break;
    }
    return n;
}

int main() {
    int a, b;
    char s;
    scanf("%d%c%d", &a, &s, &b);
    printf("%d", jisuan(a, s, b));
    return 0;
}