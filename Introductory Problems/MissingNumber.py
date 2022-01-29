from functools import reduce
n = int(input())
print(reduce(lambda x,y: x^y, list(map(int,input().split()))) ^ reduce(lambda x,y: x^y, [_ for _ in range(n+1)]))