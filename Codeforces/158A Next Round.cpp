n, k = [int(x) for x in input().split()]
l = input().split()

ans = 0
for i in l:
	if (int(i) >= int(l[k-1])) and (int(i) > 0):
		ans += 1
print(ans)