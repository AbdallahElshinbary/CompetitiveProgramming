n = int(input())
l = [int(x) for x in input().split()]

x = [1]*n
for i in range(n):
    x[l[i]-1] = i+1

for i in x: print(i, end=' ')