n = int(input())
a = input()
b = input()

ans = 0
for i in range(len(a)):
    x = min(int(a[i]), int(b[i]))
    y = max(int(a[i]), int(b[i]))
    ans += min(y-x, x+9-y+1)
print(ans)