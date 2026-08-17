# 给你一个由数字0到9组成的字符串s。
# 在一次操作中，你可以选择字符串中的任意一个数字（不能是0，也不能是最左边的数字），将其减1，然后将其与左侧相邻的数字交换位置。
# 例如，对字符串1023进行一次操作，你可以得到1103或1022。
# 求经过任意次操作后，你能得到的字典序最大的字符串。
# 输入格式
# 输入的第一行包含一个整数t（1 ≤ t ≤ 10^4）——表示测试用例的数量。
# 每个测试用例只有一行，包含一个数字字符串s（1 ≤ |s| ≤ 2·10^5），其中|s|表示字符串s的长度。该字符串没有前导零。
# 保证所有测试用例的|s|之和不超过2·10^5。
# 输出格式
# 对于每个测试用例，在单独的一行中输出答案。
import sys

def solve():
    input = sys.stdin.readline
    t = int(input())
    res = []
    for _ in range(t):
        n = input().strip()
        arr = []
        for c in n:
            arr.append(ord(c) - ord('0'))
        m = len(n)
        for i in range(0, m):
            for j in range(i + 1, min(m, i + 10)):
                cur = arr[j] - (j - i)
                if cur > arr[i]:
                    for p in range(j, i, -1):
                        arr[p] = arr[p - 1]
                    arr[i] = cur
        ans = "".join(map(str, arr))
        res.append(ans)
    sys.stdout.write("\n".join(res))

if __name__ == '__main__':
    solve()