// 史蒂夫做出了在夜间挖矿的愚蠢决定，并遭遇了一种可怕的怪物：鸡骑士n（chicken jockey n）！
// 一个鸡骑士n由按顺序堆叠在一起的n个生物组成，生物1在底部，生物n在顶部。生物i初始拥有hi点生命值。
// 在一次攻击中，史蒂夫可以对任意生物造成1点伤害。如果任何生物的生命值降至0或更低，它就会死亡，其上方所有的生物都会掉落并形成一个新的堆叠。新堆叠中的底部生物会受到相当于其掉落前所处位置上方生物数量的坠落伤害（即原堆叠中位于它下方的生物数量，包含刚刚死亡的那个）。这可能会直接导致它也死亡，在这种情况下，它上方的所有生物会再次掉落，此过程循环往复。
// 例如，考虑一个初始生物生命值为 [1,2,1,3,5,2] 的鸡骑士6。如果史蒂夫攻击堆叠中的第三个生物，它会死亡，生命值为 [3,5,2] 的生物会掉落并形成新的堆叠。底部生物受到3点坠落伤害，因此它也死亡了，生命值为 [5,2] 的生物会掉落并形成新的堆叠。底部生物受到1点坠落伤害。结果，在史蒂夫的第一次攻击后，将会剩下两个堆叠，生命值分别为 [1,2] 和 [4,2]。
// 史蒂夫的剑耐久度很低，所以他想知道消灭所有生物所需的最少攻击次数。
// 输入
// 每个测试包含多个测试用例。第一行包含测试用例的数量 t (1≤t≤10^4)。接下来是对测试用例的描述。
// 每个测试用例的第一行包含一个整数 n (2≤n≤2⋅10^5) —— 生物的数量。
// 每个测试用例的第二行包含 n 个整数 h1, h2, …, hn (1≤hi≤10^9) —— 每个生物的初始生命值。
// 保证所有测试用例中 n 的总和不超过 2⋅10^5。
// 输出
// 对于每个测试用例，输出一个整数 —— 消灭所有生物所需的最少攻击次数。
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
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
string s = " ";

void solve() {
	int n;
	cin >> n;
	vector<ll> arr(n + 1);
	vector<ll> dp(n + 1);
	for (int i = 1; i <= n; i++) cin >> arr[i];
	dp[0]=0;
	dp[1]=arr[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + max(arr[i] - 1, (ll)0); //先处理完前 i-1 个，最后手动打第 i 个
		dp[i] = min(dp[i], dp[i - 2] + arr[i - 1] + max(arr[i] - (i - 1), (ll)0)); //怪物 i 下面死 i-1 个 → 最多吃 i-1 点免费伤害
		//让第 i 个怪物，一次性吃满【最多的免费坠落伤害】，省最多的手动攻击！
	}
	cout << dp[n] << enl;
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