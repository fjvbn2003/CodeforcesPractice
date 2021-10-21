
# 못 풀어서 https://github.com/kth990303/Baekjoon/blob/master/22936_prefix_sum.cpp
# 이분 것 참고.
MAX = 60000
def solve():
    N = int(input())
    M = int(input())
    T  =7*N
    p = [0 for _ in range(MAX)]
    pp = [0 for _ in range(MAX)]
    d  = [0 for _ in range(MAX)]

    schedules = []
    for i in range(M):
        S, E = map(int, input().split())
        schedules.append([S, E])
        # 시작점을 1증가 & 끝점+1을 1감소하는 매우 신기한 아이디어.
        # 누적합을 했을 때 겹치는 구간을 표현할 수 있게 됨.
        pp[S]+=1;
        pp[E+1]-=1

    for i in range(1, MAX):
        p[i] = p[i-1]+pp[i]
        d[i] = d[i-1] +p[i]

    # debugging pp

    # print("pp")
    # for i in range(100):
    #     print(pp[i], end=" ")
    # # 현재 날짜에 몇개의 일정이 존재하는지.
    # print("\np")
    # for i in range(100):
    #     print(p[i], end=" ")
    # #
    # print("\nd")
    # for i in range(100):
    #     print(d[i], end=" ")

    ans = 0
    idx = -1
    for i in range(T, MAX):
        if(ans < d[i] - d[i-T]):
            ans = d[i]-d[i-T]
            idx = i-T+1
    # idx에는 최대 면적이 담겨있다.
    res = 0
    print("idx ",idx)
    for j in range(N):
        for i in range(M):
            # 조건 1: 끝나는 시간이 현재 구간의 시작보다 크거나 같아야 하고
            # 조건 2: 시작 시간이 현재 구간의 끝 시간보다 작아야 한다. (뒤에 조건이 없다면 구간 [3,9]에 16, 16이 들어갈 수 있다.
            if( schedules[i][1] >= idx+ 7*j and schedules[i][0] <= idx + 7*(j+1) -1):
                print("idx+ 7*j: ", idx+ 7*j, " idx + 7*(j+1) -1: ", idx + 7*(j+1) -1)
                print(" schedules[i][0]: ", schedules[i][0], "schedules[i][1]: ", schedules[i][1])
                res+=1
    print(res)

if __name__ =="__main__":
    solve()