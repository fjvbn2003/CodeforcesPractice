import re
def check_star_vega(signal):
    pattern  = re.compile("(100+1+|01)+")
    return pattern.fullmatch(signal)
if __name__ == "__main__":
    T = int(input())
    while T>0:
        T -=1
        pt = input()
        if(check_star_vega(pt)):
            print("YES")
        else:
            print("NO")
    

