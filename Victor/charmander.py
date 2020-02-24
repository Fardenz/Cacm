import random

max_p = 65000
n_iter = 10

def fermat(n):
    for i in range(n_iter):
        a = random.randint(2,n-1)
        pm = pow(a,n,n)
        if pm != a:
            return False
    return True

aux = [True]*max_p
for n in range(2,max_p):
    if aux[n]:
        for m in range(2*n,max_p,n):
            aux[m] = False

n = int(input())

while n != 0:
    #print(n,fermat(n))
    if fermat(n) and not aux[n]:
        print("The number %d is a Carmichael number." % (n))
    else:
        print("%d is normal." % (n))
    n = int(input())
