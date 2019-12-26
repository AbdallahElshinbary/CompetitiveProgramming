n = int(input())
x, mx = 0, 0
for i in range(n):
    a, b = input().split()
    x = x - int(a) + int(b)
    mx = max(mx, x)
print(mx)