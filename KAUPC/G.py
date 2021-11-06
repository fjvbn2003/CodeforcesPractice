


def solve():
    n = int(input())
    graph = [[] for _ in range(n)]
    for i in range(n-1):
        a, b = map(int, input().split())
        a-=1
        b-=1
        graph[a].append(b)
        graph[b].append(a)

    q = int(input())
    for i in range(q):
        query = list(map(int, input().split()))



if __name__ =="__main__":
    solve()