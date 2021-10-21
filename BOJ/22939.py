# BOJ 22939 쿠키크루

N = int(input())
arr = []
# 0: J, 1: C, 2: B, 3: W
top_to_num = dict()
top_to_num['J'] = 0
top_to_num['C'] = 1
top_to_num['B'] = 2
top_to_num['W'] = 3
categories = dict()
categories[0] = "Assassin"
categories[1] = "Healer"
categories[2] = "Mage"
categories[3] = "Tanker"
toppings = [[] for _ in range(4)]

home = None
exit = None
for i in range(N):
    s = input()
    arr.append(s)
    for j in range(N):
        if s[j] in ["J", "C" , "B", "W"]:
            toppings[top_to_num[s[j]]].append((i,j))
        if s[j]=="H":
            home = (i,j)
        if s[j] =="#":
            exit = (i,j)
#
# print(arr)
# print(toppings)
# print(home)
# print(exit)

# brute_force itertools이용. BFS 사용하지 않아도 됨.
# home-> 과자3개 -> exit이 가장 빠른 것.
from itertools import permutations

min_dist = 1234567890
min_idx = -1
for idx, each_toppings in enumerate(toppings):
    #print(each_toppings)
    for shuffle_toppings in permutations(each_toppings):
        #print(shuffle_toppings)
        dist = 0
        start = home
        for i in shuffle_toppings:
            # 맨하단 거리가 최단거리
            # 중간에 다른 쿠키를 피해갈 필요가 없음.
            dist+= (abs(start[0]-i[0]))
            dist+= (abs(start[1]-i[1]))
            start = i
        dist+= (abs(start[0]-exit[0]))
        dist+= (abs(start[1]-exit[1]))
        if dist <min_dist:
            #print(categories[idx], " has min dist: ", dist ,shuffle_toppings )
            min_dist = min(min_dist, dist)
            min_idx = idx


print(categories[min_idx])