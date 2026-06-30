//给定一个包含 n​ 个数字的数组 a，以及一个数字 k。
//值 aᵢ​ 表示第 i​ 天的天气：
//如果 aᵢ = 1，表示那天下雨；
//如果 aᵢ = 0，表示那天天气良好。
//Jean 想要尽可能多地登山（访问山峰）。
//一次登山恰好需要 k​ 天，并且在这 k​ 天里的每一天天气都必须良好（即 aⱼ = 0）。
//形式上，他只能在满足以下条件时在第 i​ 天开始登山：
//对所有满足 i ≤ j ≤ i + k − 1​ 的 j，都有 aⱼ = 0。
//每次登山结束后，在开始下一次登山之前，Jean 必须至少休息一天，也就是说，在一次登山结束后的第二天，他不能立即开始另一次登山。
//请计算 Jean 最多能完成多少次登山。
//输入
//每个测试包含多个测试用例。
//第一行包含一个整数 t（1 ≤ t ≤ 10⁴）——测试用例的数量。接下来是测试用例的描述。
//每个测试用例的第一行包含两个整数 n​ 和 k（1 ≤ n ≤ 10⁵，1 ≤ k ≤ n）。
//第二行包含 n​ 个数 aᵢ（aᵢ ∈ {0, 1}），其中 aᵢ​ 表示第 i​ 天的天气。
//保证所有测试用例中 n​ 的总和不超过 10⁵。
//输出
//对于每个测试用例，输出一个整数：Jean 能够完成的最大登山次数。
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (arr[j] == 0 && j - i < k && j < n) {
            j++;
        }
        if (j - i == k) cnt++;
        if (i != j) i = j;
    }
    cout << cnt << enl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}