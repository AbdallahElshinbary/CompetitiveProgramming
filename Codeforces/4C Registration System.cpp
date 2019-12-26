n = int(input())
d = {}
for i in range(n):
    x = input()
    if x in d.keys():
        d[x]+=1
        print(x + str(d[x]))
    else:
        print("OK")
        d[x] = 0
