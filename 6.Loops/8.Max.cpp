//在输入的数字中找到最大值
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums[i] = num;
    }
    int max = nums[0];
    for (int i = 1; i < n; ++i) {
        if (nums[i] > max) max = nums[i];
    }
    cout << max << endl;
    return 0;
}