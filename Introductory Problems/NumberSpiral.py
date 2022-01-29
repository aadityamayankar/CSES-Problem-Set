t = int(input())
for _ in range(t):
    x,y = map(int,input().split())
    mx = max(x,y)
    print((x-y)*(-1)**mx+mx*mx-mx+1)