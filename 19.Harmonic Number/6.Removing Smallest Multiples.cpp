//删除最小倍数的总和，让集合s转换成集合t
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void solve(string s) {
    vector<int> nums(s.size() + 1, 0);  //存缺少的数为1
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            nums[i + 1] = 1;
        }
    }
    long long res = 0;
    for (int i = 1; i < nums.size(); ++i) { //遍历
        for (int j = i; j < nums.size(); j += i) { //按倍数找
            if (s[j - 1] == '1') break;
            if (nums[j] == 1) {
                nums[j] = 0;  //找到就变成0,把它最小倍数加上
                res += i;
            }
        }
        
    }
    cout << res << '\n';
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r",  stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        solve(s);
    }
}