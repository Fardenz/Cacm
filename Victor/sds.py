n = 1
f = 1
d = 1
a = {}
a[f] = n
while n <= 2*10**9:
    if a[d] == f:
        d += 1
    n += d
    f += 1
    a[f] = n
    
n = int(input())

while n != 0:
    print(next(x[0] for x in a.items() if x[1] >= n))
    n = int(input())