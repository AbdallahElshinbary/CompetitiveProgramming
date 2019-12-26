x = input()
w = "hello"
i = 0
for c in x:
    if c == w[i]:
        i += 1
    if i == len(w): break

print("YES" if i == len(w) else "NO")
