ans = 0
for i in range(5):
    x = input().split()
    if '1' in x:
        ans = abs(i-2)+abs(x.index('1')-2)
print(ans)