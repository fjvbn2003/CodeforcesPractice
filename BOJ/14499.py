# BOJ 14499 https://www.acmicpc.net/problem/14499
# author: Youngju Kim

import copy



N, M, x,y,K = map(int, input().split())

arr = [[0 for _ in range(M)] for __ in range(M)]
##동서북남
directions = [[0,1], [0, -1], [-1, 0], [1,0]]
for i in range(N):
    tmp_row = list(map(int, input().split))
    for j in tmp_row:
        arr[i][j] = tmp_row[j]
