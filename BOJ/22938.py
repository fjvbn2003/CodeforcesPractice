# BOJ 22938 백발백준하는 명사수
def solve():
    x1, y1, r1 = map(int, input().split())
    x2, y2, r2 = map(int, input().split())
    dist = pow(abs(x1-x2),2)+ pow(abs(y1-y2),2)
    if(pow(r1+r2, 2) <= dist):
        print("NO")
    else:
        print("YES")

    return


if(__name__ =="__main__"):
    solve()