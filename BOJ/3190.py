import copy
from collections import deque
N = 0
# 동남서북
directions = [[0,1], [1, 0], [0, -1], [-1, 0]]
direction_history = deque()

def print_map(arr):
    global N
    for i in range(N):
        for j in range(N):
            print(arr[i][j], end=' ')
        print()

if __name__ =="__main__":
    N = int(input())
    K = int(input())
    arr = [ [0 for _ in range(N) ] for __ in range(N) ]
    for _ in range(K):
        r, c = map(int, input().split())
        arr[r-1][c-1] = 1
    
    L = int(input())
    for i in range(L):
        time, rotation = input().split()
        direction_history.append([int(time), rotation])
    
    snake = deque()
    # y, x, direction
    snake.append([0,0,0])
    arr[0][0] = 2
    # simulate
    time = 0
    while True:
        y, x, d = snake[0]
        ny = y + directions[d][0]
        nx = x + directions[d][1]
        if ny <0 or ny >=N or nx <0 or nx >= N:
            break
        # 사과가 있을 경우
        elif arr[ny][nx] == 1:
            arr[ny][nx] = 2
            snake.appendleft([ny,nx,d])
        # 몸통을 만난 경우
        elif arr[ny][nx] == 2:
            break
        # 빈 공간의 경우
        else:
            arr[ny][nx] = 2
            snake.appendleft([ny,nx,d])
            arr[snake[-1][0]][snake[-1][1]] = 0
            snake.pop()
        time +=1
        # print("time: ", time)
        # print_map(arr)
        if len(direction_history) >0 and direction_history[0][0] == time:
            if direction_history[0][1] == 'D':
                snake[0][2] = (snake[0][2]+1)%4
            elif direction_history[0][1] == 'L':
                snake[0][2] = (snake[0][2]-1)%4
            direction_history.popleft()
    print(time+1)