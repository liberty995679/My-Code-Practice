//大小写转换
#include <iostream>
using namespace std;
int main() {
    char x;
    cin >> x;
    if (x >= 'a' & x <= 'z') {
        printf("%c",x - 'a' + 'A');
    } else if (x >= 'A' && x <= 'Z') {
        printf("%c",x - 'A' + 'a');
    }
    return 0;
}