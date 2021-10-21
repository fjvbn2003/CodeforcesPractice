N, M = map(int, input().split())
ones = []

for i in range(N):
    tmp = list(map(int, input().split()))
    for j in range(M):
        if tmp[j]==1:
            ones.append((i, j))

print(abs(ones[0][0]-ones[1][0])+abs(ones[0][1]-ones[1][1]))