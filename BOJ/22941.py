def solve():
    hp, at, ma_hp, ma_at = map(int, input().split())
    P, S = map(int, input().split())
    # if(ma_hp//at < hp//ma_at):
    #     print("gg")
    #     return
    if ((at == 1 or ma_hp % at != 0) and ma_hp % at <= P):
        # print("in S")
        ma_hp += S

    c_ma = ma_hp // at
    if (ma_hp % at > 0): c_ma += 1
    c_yong = hp // ma_at
    if (hp % ma_at > 0): c_yong += 1
    # print("cma: ", c_ma," c_youg:", c_yong)
    if (c_yong >= c_ma):
        print("Victory!")
    else:
        print("gg")

    return


if (__name__ == "__main__"):
    solve()
