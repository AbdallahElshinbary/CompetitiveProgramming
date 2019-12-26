n = int(input())
d = {"Tetrahedron": 4, "Cube": 6, "Octahedron": 8, "Dodecahedron": 12, "Icosahedron": 20}

ans = 0
for i in range(n):
    x = input()
    ans += d[x]
print(ans)