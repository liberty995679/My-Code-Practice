//判断一个数在哪个区间
#include <iostream>
using namespace std;
int main() {
    double x;
    cin >> x;
    if (x >= 0 && x <= 100) {
        if (x > 75) {
            cout << "Interval (75,100]"  << endl;
        } else if (x > 50) {
            cout << "Interval (50,75]"  << endl;
        } else if (x > 25) {
            cout << "Interval (25,50]"  << endl;
        } else {
            cout << "Interval [0,25]"  << endl;
        }
    } else {
        cout << "Out of Intervals" << endl;
    }
    return 0;
}