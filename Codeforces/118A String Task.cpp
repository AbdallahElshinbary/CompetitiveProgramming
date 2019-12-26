s = input()
l = list(s)

vowels = ["a", "o", "y", "e", "u", "i"]

for c in range(len(l)):
	l[c] = l[c].lower()
	if l[c] in vowels:
		l[c] = ''
	else:
		l[c] = '.'+l[c]

print("".join(l))