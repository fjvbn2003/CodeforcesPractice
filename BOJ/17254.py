N, M = map(int, input().split())
arr = []
for i in range(M):
    t = list(input().split())
    a = int(t[0])
    b = int(t[1])
    c = t[2]
    arr.append([b,a,c])
arr = sorted(arr, key=lambda x: (x[0], x[1]))
for i in arr:
    print(i[2],end="")
print()