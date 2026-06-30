//对数组里的数字进行交换，正数为1，负数位2，0不变
#include <iostream>

using namespace std;

const int N = 1005;

int main() {
    int n;
    cin >> n;
    int nums[N] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (nums[i] > 0) nums[i] = 1;
        else if (nums[i] == 0) continue;
        else nums[i] = 2;
    }
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    return 0;
}