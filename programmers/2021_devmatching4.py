from collections import defaultdict, deque
from itertools import combinations
import re
from collections import Counter
import copy

dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]

def print_board(board):
    for i in range(len(board)):
        for j in range(len(board[0])):
            print(board[i][j], end=" ")
        print()


def bfs(visited, board, i ,j):
    visited[i][j] = True
    queue = deque()
    queue.append([i, j])

    tmp_visited_list = []

    while queue:
        y, x = queue.popleft()
        tmp_visited_list.append([y, x])

        for k in range(4):
            ny, nx = y + dy[k], x + dx[k]
            if 0 <= ny < len(board) and 0 <= nx < len(board[0]):
                if not visited[ny][nx] and board[ny][nx] == board[i][j]:
                    visited[ny][nx] = True
                    queue.append([ny, nx])

    return tmp_visited_list


def bomb_board(board, stacks):
    visited = [[False] * len(board[0]) for _ in range(len(board))]
    for i in range(len(board)):
        for j in range(len(board[0])):
            if not visited[i][j] and board[i][j] != 0:
                tmp_visited_list = bfs(visited, board, i, j)

                if len(tmp_visited_list) >= 3:
                    for y, x in tmp_visited_list:
                        board[y][x] = -1


def change_board(board, stacks):
    board = [[0] * 6 for _ in range(6)]
    for j in range(6):
        i = 5
        stack_copy = copy.deepcopy(stacks[j])

        while stack_copy:
            board[i][j] = stack_copy.pop(0)
            i -= 1

    bomb_board(board, stacks)

    return board


def change_stack(board):
    stacks = [[] for _ in range(6)]
    for j in range(6):
        for i in range(5, -1, -1):
            if board[i][j] not in [0, -1]:
                stacks[j].append(board[i][j])
    return stacks


def is_bombed(board):
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == -1:
                return True
    return False


def solution(macaron):
    answer = []
    board = [[0] * 6 for _ in range(6)]
    stacks = [[] for _ in range(6)]
    bombed = False

    for mac in macaron: #  [떨어뜨린 위치, 마카롱의 색]
        pos, color = mac[0] -1, mac[1]
        stacks[pos].append(color)
        board= change_board(board, stacks)
        bombed = is_bombed(board)
        stacks = change_stack(board)

        while bombed:
            board = change_board(board, stacks)
            stacks = change_stack(board)
            bombed = is_bombed(board)

    board = change_board(board, stacks)
    for i in range(6):
        answer.append(''.join(map(str, board[i])))
    return answer


print(solution([[1,1],[2,1],[1,2],[3,3],[6,4],[3,1],[3,3],[3,3],[3,4],[2,1]]) == ["000000","000000","000000","000000","000000","204004"])
print(solution([[1,1],[1,2],[1,4],[2,1],[2,2],[2,3],[3,4],[3,1],[3,2],[3,3],[3,4],[4,4],[4,3],[5,4],[6,1]]) == ["000000","000000","000000","000000","000000","404001"])