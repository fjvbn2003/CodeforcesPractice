# BOJ 13460
# https://www.acmicpc.net/problem/13460
import copy


# 4^10 = 1000,000
# 왼쪽, 오른쪽, 위, 아래로 움직이는 경우의 수를 모두 탐색해보자.
# 만약 구슬이 모두 움직이지 않으면 중지한다.
def print_arr(arr):
    for i in range(N):
        for j in range(M):
            print(arr[i][j], end='')
        print()


directions = [[0 ,-1], [0,1], [-1,0], [1, 0]]
best_score = 11 
N, M = map(int, input().split()) 
initial_arr = [['' for i in range(M)] for j in range(N)]

def find_marble_idx(arr, color):
    for i in range(N):
        for j in range(M):
            if arr[i][j] == color:
                return (i, j)

    return (-1, -1)
# return 1 if only red goes to the hole
# else if marble is not moving return -1
# else return 0
def incline(arr, op):
    direction = directions[op]
    R_y, R_x = find_marble_idx(arr, 'R')
    if R_y ==-1 and R_x ==-1:
        return
    B_y, B_x = find_marble_idx(arr, 'B')
    if B_y ==-1 and B_x ==-1:
        return
    o_R_y = R_y
    o_B_y = B_y
    o_R_x = R_x
    o_B_x = B_x
    # red move
    red_move_cnt =0
    red_is_fall = False
    while True:
        n_R_y = R_y+ direction[0]
        n_R_x = R_x+ direction[1]
        if arr[n_R_y][n_R_x] == 'O':
            R_y = n_R_y
            R_x = n_R_x
            red_is_fall = True
            break
        elif arr[n_R_y][n_R_x] == '#':
            break
        red_move_cnt +=1
        R_y = n_R_y
        R_x = n_R_x
    # blue move
    blue_move_cnt =0
    blue_is_fall = False
    while True:
        n_B_y = B_y+ direction[0]
        n_B_x = B_x+ direction[1]
        # print_arr(arr)
        # print(arr[n_B_y][n_B_x])
        # print(n_B_y, n_B_x)
        if arr[n_B_y][n_B_x] == 'O':
            B_y = n_B_y
            B_x = n_B_x
            blue_is_fall = True
            break
        elif arr[n_B_y][n_B_x] == '#':
            break
        blue_move_cnt +=1
        B_y = n_B_y
        B_x = n_B_x
    
    # success
    if red_is_fall and blue_is_fall != True:
        return 1
    # if blue and red is fall same time return false
    if red_is_fall and blue_is_fall:
        return -1
    # not moving
    if R_y == o_R_y and o_R_x == R_x and B_y == o_B_y and B_x == o_B_x :
        return -1
    
    if R_x == B_x and R_y == B_y:
        if red_move_cnt > blue_move_cnt:
            R_y -= direction[0]
            R_x -= direction[1]
        else:
            B_y -= direction[0]
            B_x -= direction[1]
    arr[o_R_y][o_R_x] = '.'
    arr[o_B_y][o_B_x] = '.'
    arr[R_y][R_x] = 'R'
    arr[B_y][B_x] = 'B'
    return 0

# brute force
def brute_force(arr, num, last_op):
    global best_score
    if num >=10:
        return
    for i in range(4):
        if last_op != i:
            copy_arr = copy.deepcopy(arr)
            ret = incline(copy_arr, i)
            if ret == 1:
                best_score = min(best_score, num+1)
                return
            elif ret == -1:
                pass
            else:
                brute_force(copy_arr, num+1, i)
    return


for i in range(N):
    tmp_line = input()
    for j in range(M):
        initial_arr[i][j] = tmp_line[j]

brute_force(initial_arr, 0, -1)
if best_score == 11:
    print(-1)
else:
    print(best_score)