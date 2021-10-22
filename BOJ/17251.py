N = int(input())
arr = list(map(int, input().split()))

max_left = [0 for _ in range(N-1)]
max_left[0] = arr[0]
for i in range(1,N-1):
    max_left[i] = max(max_left[i-1],arr[i])
max_right = [0 for _ in range(N-1)]
max_right[0] = arr[N-1]
for i in range(1, N-1):
    max_right[i] = max(max_right[i-1],arr[N-i-1])

left_win = 0
right_win = 0
for i in range(N-1):
    if(max_left[i] > max_right[N-2-i]):
        left_win+=1
    elif(max_left[i] < max_right[N-2-i]):
        right_win+=1
if(left_win>right_win):
    print("R")
elif(left_win <right_win):
    print("B")
else:
    print("X")
