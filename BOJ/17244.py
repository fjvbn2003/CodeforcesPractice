N, M = map(int, input().split())
arr = []
for i in range(M):
    s = input()
    arr.append(s)

start = None
exit = None
somethings = []
for i in range(M):
    for j in range(N):
        if arr[i][j]=="S":
            start = (i, j)
        if arr[i][j] =="E":
            exit = (i, j)
        if arr[i][j] == "X":
            somethings.append((i, j))

# print(somthings)
# print(start)
# print(exit)

from itertools import permutations
from collections import deque
D = [[0,1],[0,-1],[1,0],[-1,0]]
def bfs(fr, to):
    q = deque()
    visited = [ [-1 for _ in range(N)] for __ in range(M)]
    visited[fr[0]][fr[1]] = 0
    q.append(fr)

    while(len(q)>0):
        cur = q[0]
        q.popleft()
        for i in range(4):
            nr = cur[0]+D[i][0]
            nc = cur[1]+D[i][1]
            if(nr<0 or nr>=M or nc<0 or nc>=N or arr[nr][nc]=="#" or visited[nr][nc]!=-1):
                continue
            if(nr==to[0] and nc==to[1]):
                return visited[cur[0]][cur[1]]+1
            visited[nr][nc] = visited[cur[0]][cur[1]]+1
            q.append((nr, nc))
    return 123456789
ans = 1234567890
for i in permutations(somethings):
    fr = start
    cand = 0
    for j in i:
        cand += bfs(fr, j)
        fr = j
    cand += bfs(fr, exit)
    ans = min(ans, cand)

print(ans)