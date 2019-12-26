l = [4, 7
    ,44, 47, 74, 77
    ,444, 447, 474, 477, 744, 747, 774, 777]

n = int(input())
for i in l:
    if n % i == 0:
        print("YES")
        exit(0)
print("NO")