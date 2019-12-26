t = int(input())
while t > 0:
	s = input()
	if len(s) > 10:
		print("".join([s[0],str(len(s)-2),s[-1]]))
	else:
		print(s)
	t -= 1