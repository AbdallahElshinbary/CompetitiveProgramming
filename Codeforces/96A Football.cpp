x = input()
c = x[0]
n = 0
flag = False
for i in x:
	if i == c:
		n += 1
	else:
		c = i
		n = 1
	if n == 7:
		flag = True
		break

print("YES" if flag else "NO")