// 两支足球队，RiOI 队和 KDOI 队，即将进行一场足球比赛。
// 一场足球比赛分为上半场和下半场两个部分。比赛开始时，两队比分均为 0。
// 作为两队的粉丝，Aquawave 知道两队水平接近，因此在同一半场内，不会有球队连续进三球。
// Aquawave 在比赛前一晚做了一个梦，梦中：
// 上半场结束时的比分为 a : b，其中 a​ 是 RiOI 队的得分，b​ 是 KDOI 队的得分；
// 下半场结束时的比分为 c : d，其中 c​ 是 RiOI 队的得分，d​ 是 KDOI 队的得分。
// 你需要根据以上信息判断 Aquawave 的梦是否可能成真。
// 输入​
// 每个测试包含多个测试用例。第一行是一个整数 t（1 ≤ t ≤ 1000），表示测试用例的数量。接下来是各测试用例的描述。
// 每个测试用例仅一行，包含四个整数 a, b, c, d（0 ≤ a ≤ c ≤ 100，0 ≤ b ≤ d ≤ 100）——分别表示上半场结束时和下半场结束时的比分。
// 输出​
// 对于每个测试用例，如果 Aquawave 的梦可能成真，则输出 "YES"；否则输出 "NO"。
// 答案不区分大小写。例如，"yEs", "yes", "Yes", "YES"都会被视为肯定回答。
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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (max(a, b) > 2 * (min(a, b) + 1)) {
		cout << "NO" << enl;
		return;
	}
	int x1 = c - a;
	int y1 = d - b;
	if (max(x1, y1) > 2 * (min(x1, y1) + 1)) {
		cout << "NO" << enl;
		return;
	}
	cout << "YES" << enl;
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