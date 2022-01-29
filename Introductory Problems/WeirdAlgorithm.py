n = int(input())
print(n, end=' ')
while n != 1:
    if not n & 1: n >>= 1
    else: n = n * 3 + 1
    print(n, end=' ')