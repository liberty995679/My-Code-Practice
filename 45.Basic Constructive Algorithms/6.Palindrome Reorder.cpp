//将一个字符串的字符重新排序，使其成为回文字符串
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solve(string s) {
    int n = s.size();
    vector<int> nums(26, 0);
    for (int i = 0; i < n; i++) nums[s[i] - 'A']++;
    bool flag = true;
    int cnt = 0;
    for (int i: nums) {
        if (i & 1) cnt++;
    }
    if (cnt > 1) flag = false;
    if (!flag) return "NO SOLUTION";
    string mid;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] & 1) mid = (char)(i + 'A');
    }
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 1) {
            nums[i] /= 2;
            string head(nums[i], i + 'A');
            mid = head + mid + head;
        }
    }
    return mid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    cout << solve(s) << endl;
    return 0;
}