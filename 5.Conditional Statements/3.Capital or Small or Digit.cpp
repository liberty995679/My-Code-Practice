//判断大小写字母数字
#include <iostream>
using namespace std;
int main() {
    char x;
    cin >> x;
    if (x >= 48 && x <= 57) {
        printf("IS DIGIT");
    } else {
        printf("ALPHA\n");
        if (x >= 65 && x <= 90) {
            printf("IS CAPITAL");
        } else if (x >= 97 && x <= 122) {
            printf("IS SMALL");
        }
    }
    return 0;
}