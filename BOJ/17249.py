s = input()

arr = list(s)
meet_face = False
left = 0
right = 0
for i in arr:
    if i=="(":
        meet_face = True
    if i=="@":
        if(meet_face):
            right+=1
        else:
            left+=1
print(left,right)