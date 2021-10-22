def solve():
    N = int(input())
    if(N==0):
        print("NO")
        return
    arr = []
    while(N>0):
        arr.append(N%3)
        N//=3
    #print(arr)
    for i in arr:
        if i==2:
            print("NO")
            return
    print("YES")
    return

if __name__ =="__main__":
    solve()