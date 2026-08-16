# 你有一个长度为 n 的数组 a。
# 在一次操作中，你可以选择一个下标 i（满足 2 ≤ i ≤ n−1），并执行以下两种动作之一：
# 将 a[i−1] 减 1，同时将 a[i+1] 加 1
# 将 a[i+1] 减 1，同时将 a[i−1] 加 1
# 每次操作后，所有元素的值必须保持非负。​
# 问：是否可以通过任意次操作，使得数组中所有元素都相等？
# 输入格式
# 第一行包含一个整数 t（1 ≤ t ≤ 10^4）——测试用例的数量。
# 每个测试用例的第一行包含一个整数 n（3 ≤ n ≤ 2·10^5）。
# 每个测试用例的第二行包含 n 个整数 a[i]（1 ≤ a[i] ≤ 10^9）。
# 保证所有测试用例的 n 之和不超过 2·10^5。
# 输出格式
# 对于每个测试用例：
# 如果可以通过若干次操作使所有元素相等，输出 "YES"
# 否则输出 "NO"
# 输出不区分大小写，例如 "yes"、"YeS"、"nO" 都会被判为正确。
import sys
def solve():
    input = sys.stdin.readline
    t = int(input())
    ans = []
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        s1 = s2 = 0
        c1 = c2 = 0
        for i, d in enumerate(a):
            if i & 1:
                s2 += d
                c2 += 1
            else:
                s1 += d
                c1 += 1
        if s1 % c1 == 0 and (s1 // c1) * c2 == s2:
            ans.append("YES")
        else:
            ans.append("NO")
    sys.stdout.write("\n".join(ans)) #一次性输出所有答案

if __name__ == '__main__':
    solve()