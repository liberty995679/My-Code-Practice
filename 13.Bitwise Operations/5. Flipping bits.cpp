//对n的比特位进行翻转
#include <iostream>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        unsigned int n;
        cin >> n;
        cout << ~n << endl;
    }
    return 0;
}