n = int(input())
ans = 0
for i in range(n):
	x = input()
	if "++" in x:
		ans += 1
	else:
		ans -= 1
print(ans)