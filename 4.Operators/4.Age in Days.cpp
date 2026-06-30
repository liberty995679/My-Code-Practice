//给天数计算年月日
#include <iostream>
using namespace std;
int main() {
    int n;
    int years, months, days;
    cin >> n;
    years = n / 365;
    n = n - 365 * years;
    months = n / 30;
    n = n - 30 * months;
    days = n % 30;
    printf("%d years\n", years);
    printf("%d months\n", months);
    printf("%d days\n", days);
    return 0;
}