from collections import defaultdict
test_case = int(input())
for _ in range(test_case):
    d = defaultdict(int)
    n = int(input())
    for i in range(n):
        a, b = input().split()
        d[b]+=1
    ans = 1
    for k,v in d.items():
        ans*=(v+1)
    ans -=1
    print(ans)
