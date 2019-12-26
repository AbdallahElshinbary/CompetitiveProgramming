a, b, c = [int(x) for x in input().split()]
print(max(0, a*(c*(c+1)//2) - b))