t = int(input())

ans = 0
for i in range(t):
	a,b,c = [int(x) for x in input().split()]
	if a+b+c >= 2:
		ans += 1
print(ans)