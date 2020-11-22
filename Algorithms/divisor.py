n = 60;
i =1;
arr = []
while(i*i <n):
    if(n%i ==0):
        arr.append(i);
        arr.append(n/i);
    i+=1
n_arr = list(map(int, sorted(arr)))
print(n_arr)