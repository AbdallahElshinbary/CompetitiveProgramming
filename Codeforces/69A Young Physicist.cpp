n = int(input())
x,y,z = 0,0,0
for i in range(n):
    l = input().split()
    x += int(l[0])
    y += int(l[1])
    z += int(l[2])
print("YES" if x == y == z == 0 else "NO")