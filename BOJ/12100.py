
# BOJ 12100 https://www.acmicpc.net/problem/12100
# Date: 2023.03.11

import copy
from collections import deque
# 상하좌우
directions =[[-1,0], [1, 0], [-1, 0], [1, 0]]
best_number = -1
N = 0
def print_array(arr):
    global N
    for i in range(N):
        for j in range(N):
            print(arr[i][j], end=' ')
        print()


def incline(arr, op):
    global best_number
    direction = directions[op]
    # 위로 기울일 때
    if op == 0:
        # all columns
        for i in range(N):
            # all row
            q = deque()
            new_row = []
            for j in range(N):
                if arr[j][i] == 0:
                    pass
                elif len(q)>0 and q[-1] == arr[j][i]:
                    q.append(q.pop()*2)
                    while len(q)>0:
                        new_row.append(q.popleft())
                else:
                    q.append(arr[j][i])
            while len(q) >0:
                new_row.append(q.popleft())
        
            while len(new_row) != N:
                new_row.append(0)
            for j in range(N):
                arr[j][i] = new_row[j]
    # 아래로 기울일 때
    elif op == 1:
        # all columns
        for i in range(N):
            # all row
            q = deque()
            new_row = []
            for j in range(N-1, -1, -1):
                if arr[j][i] == 0:
                    pass
                elif len(q)>0 and q[-1] == arr[j][i]:
                    q.append(q.pop()*2)
                    while len(q)>0:
                        new_row.append(q.popleft())
                else:
                    q.append(arr[j][i])
            while len(q) >0:
                new_row.append(q.popleft())
            while len(new_row) != N:
                new_row.append(0)
            for j in range(N-1,-1, -1):
                arr[j][i] = new_row[N-1-j]
    #왼쪽으로 기울일 때
    elif op == 2:
        # all rows
        for i in range(N):
            # all columns
            q = deque()
            new_row = []
            for j in range(0, N):
                if arr[i][j] == 0:
                    pass
                elif len(q)>0 and q[-1] == arr[i][j]:
                    q.append(q.pop()*2)
                    while len(q)>0:
                        new_row.append(q.popleft())
                else:
                    q.append(arr[i][j])
            while len(q) >0:
                new_row.append(q.popleft())
            while len(new_row) != N:
                new_row.append(0)
            for j in range(0,N):
                arr[i][j] = new_row[j]
    #오른쪽으로 기울일 때
    elif op == 3:
        # all rows
        for i in range(N):
            # all columns
            q = deque()
            new_row = []
            for j in range(N-1, -1, -1):
                if arr[i][j] == 0:
                    pass
                elif len(q)>0 and q[-1] == arr[i][j]:
                    q.append(q.pop()*2)
                    while len(q)>0:
                        new_row.append(q.popleft())
                else:
                    q.append(arr[i][j])
            while len(q) >0:
                new_row.append(q.popleft())
            while len(new_row) != N:
                new_row.append(0)
            for j in range(N-1,-1, -1):
                arr[i][j] = new_row[N-1-j]                
    
    for i in range(N):
        for j in range(N):
            best_number = max(best_number, arr[i][j])
def brute_force(num, arr):
    if num >5: 
        return
    for i in range(4):
        copy_arr = copy.deepcopy(arr)
        incline(copy_arr, i)
        # if i ==1:
        #     print("before ")
        #     print_array(arr)
        #     print("op ", i)
        #     print_array(copy_arr)
        brute_force(num+1, copy_arr)
    return


# python 에서 main 함수는 전역변수 global 선언안해도 바로 사용가능.
if __name__ == "__main__":
    N = int(input())
    arr = [[0 for _ in range(N)] for __ in range(N)]
    for i in range(N):
        tmp_rows = list(map(int, input().split()))
        for j in range(N):
            arr[i][j] = tmp_rows[j]
            best_number = max(best_number, tmp_rows[j])
    brute_force(1, arr)
    print(best_number)
