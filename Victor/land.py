cases = int(input())

for case in range(cases):
    n = int(input())
    print((n**4 - 6*n**3 + 23*n**2 - 18*n + 24)//24)