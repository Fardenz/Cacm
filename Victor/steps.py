import math as m

memo = {}
memo[0], memo[1], memo[2], memo[3] = 0,1,2,3
counter = 2
aux = 0
prev = 3
while aux+counter < 2**31:
    aux = counter**2
    memo[aux] = prev
    prev += 1
    memo[aux+counter] = prev
    prev += 1
    counter += 1

#print(memo)

cases = int(input())

for case in range(cases):
    aux = list(map(int,input().split()))
    #print(aux)

    n = aux[1]-aux[0]
    print(next(x[1] for x in memo.items() if x[0] >= n))
