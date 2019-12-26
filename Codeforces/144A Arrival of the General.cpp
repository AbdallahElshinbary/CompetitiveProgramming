n = int(input())
l = [int(x) for x in input().split()]

mx = max(l)
mn = min(l)

a = l.index(mx)
b = len(l) - l[::-1].index(mn) - 1

ans = a + len(l)-b-1
if a > b: ans -= 1
print(ans)