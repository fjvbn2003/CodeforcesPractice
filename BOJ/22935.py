# BOJ 22935 이진딸기
from collections import deque
def solve():
    test_case = int(input())
    for i in range(test_case):
        n = int(input())
        n-=1 # zero_index
        n = n%28
        if(n>14):
            n = 13-(n-15)
        #print(n)
        n+=1
        dq = deque()
        while(n>0):
            dq.appendleft("딸기" if n%2==1 else "V")
            n = n//2
        while(len(dq)<4):
            dq.appendleft("V")
        print("".join(dq))
if(__name__ == "__main__"):
    solve()