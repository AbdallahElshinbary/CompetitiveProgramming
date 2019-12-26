n = int(input())
x = sorted([int(x) for x in input().split()], reverse=True)
sum = 0
for i in x: sum += i
sum = sum / 2
m, ans = 0, 0
for i in x:
    m += i
    ans += 1
    if m > sum: break
print(ans)
