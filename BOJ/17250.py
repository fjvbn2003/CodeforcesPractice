from collections import deque

# union_find


def find_parent(x, parent):
    #print("in parent: ", x, parent)
    if x != parent[x]:
        parent[x] = find_parent(parent[x], parent)
        return parent[x]
    return x

def union_parent(a,b,parent):
    a = find_parent(a,parent)
    b = find_parent(b,parent)
    if(a<b):
        parent[b] = a
    else:
        parent[a]  =b


def solve():
    N , M = map(int, input().split())
    arr = []
    parent = [0 for i in range(N)]
    for i in range(N):
        parent[i] = i

    visited = [False for _ in range(N)]
    answers = [0 for _ in range(N)]
    for i in range(N):
        arr.append(int(input()))
        answers[i] = arr[i]
    for i in range(M):
        a, b = map(int, input().split())
        a-=1
        b-=1
        #print("a, b: ",a,b)
        #print(find_parent(a,parent), find_parent(b,parent))

        if(find_parent(a, parent) != find_parent(b, parent)):
            #print("find_parent: ",find_parent(a), find_parent(b))
            if(visited[find_parent(a, parent)] == False):
                visited[find_parent(a, parent)] = True
                #print("arr[a]: ", arr)
            if(visited[find_parent(b, parent)] == False):
                visited[find_parent(b, parent)] = True
            if(find_parent(a,parent)< find_parent(b,parent)):
                answers[find_parent(a,parent)] += answers[find_parent(b,parent)]
            else:
                answers[find_parent(b,parent)] += answers[find_parent(a,parent)]
            union_parent(a,b, parent)

        #print("answer[i]: ",answers[find_parent(a, parent)])
        print(answers[find_parent(a,parent)])

if __name__ =="__main__":
    solve()