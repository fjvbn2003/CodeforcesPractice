S = input()
N = len(S)
st = set()
def dfs(left, right, path):
    if(right-left == N):
        st.add(path)
        return
    if(left>0):
        new_path = path + S[left-1:right]
        dfs(left-1, right, new_path)
    if(right<N):
        new_path = path + S[left:right+1]
        dfs(left, right+1, new_path)
    return


for i in range(N):
    dfs(i, i+1, S[i])

print(len(st))