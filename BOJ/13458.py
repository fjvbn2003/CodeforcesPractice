# BOJ 13458 https://www.acmicpc.net/problem/13458
import math
N = int(input())
arr = map(int, input().split())
B,C = map(int, input().split())
answer =0
for i in arr:
    i -= B
    answer +=1
    if i>0:
        answer += math.ceil(i/C)
print(answer)