a = int(input())
b = int(input())
c = int(input())

l = []
l.append(a*b*c)
l.append(a+b+c)
l.append((a+b)*c)
l.append((a*b)+c)
l.append(a+(b*c))
l.append(a*(b+c))

print(max(l))
