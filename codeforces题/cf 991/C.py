# 给你一个数字 n，它的长度不超过 10^5。
# 你可以进行以下操作任意多次：选择这个数字中的某一位，将其平方，并用结果替换原来的那一位。替换后的结果必须仍然是一个数字（也就是说，如果你选择的数字是 x，那么 x^2 的值必须小于 10）。
# 问：通过这些操作，能否得到一个能被 9 整除的数字？
# 输入
# 第一行包含一个整数 t（1 ≤ t ≤ 10^4）—— 测试用例的数量。
# 每个测试用例的唯一一行给出数字 n，没有前导零。数字的长度不超过 10^5。
# 保证所有测试用例中数字的长度之和不超过 10^5。
# 输出
# 对于每个测试用例，如果可以通过上述操作得到一个能被 9 整除的数字，输出 "YES"，否则输出 "NO"。
# 每个字母可以用任意大小写输出。例如，字符串 "yEs"、"yes"、"Yes" 和 "YES" 都会被接受为正答案。
import sys
def solve():
    input = sys.stdin.readline
    t = int(input())
    ans = []
    for _ in range(t):
        n =  input().strip()
        cnt2 = 0
        cnt3 = 0
        sum = 0
        for i in range(0, len(n)):
            sum += ord(n[i]) - ord('0')
            if n[i] == '2':
                cnt2 += 1
            elif n[i] == '3':
                cnt3 += 1
        found = False
        for a in range(0, min(cnt2, 9) + 1):
            for b in range(0, min(cnt3, 9) + 1):
                if (sum + 2 * a + 6 * b) % 9 == 0:
                    found = True
                    break
            if found:
                break
        ans.append("YES" if found else "NO")
    sys.stdout.write("\n".join(ans))

if __name__ == '__main__':
    solve()