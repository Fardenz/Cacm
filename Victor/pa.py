aux = list(map(int,input().split()))

while aux != [0,0]:
    result = 0
    carry = 0
    while aux[0] > 0 and aux[0] > 0:
        #print((aux[0]%10),(aux[1]%10),carry,(aux[0]%10)+(aux[1]%10)+carry)
        if (aux[0]%10)+(aux[1]%10)+carry >= 10:
            result += 1
            carry = 1
        else:
            carry = 0
        aux[0] = aux[0]//10
        aux[1] = aux[1]//10

    while aux[0] > 0:
        #print((aux[0]%10),carry,(aux[0]%10)+carry)
        if (aux[0]%10)+carry >= 10:
            result += 1
            carry = 1
        else:
            carry = 0
        aux[0] = aux[0]//10

    while aux[1] > 0:
        #print((aux[1]%10),carry,(aux[1]%10)+carry)
        if (aux[1]%10)+carry >= 10:
            result += 1
            carry = 1
        else:
            carry = 0
        aux[1] = aux[1]//10
    
    if result == 0:
        print("No carry operation.")
    elif result == 1:
        print("1 carry operation.")
    else:
        print(str(result) + " carry operations.")
        
    aux = list(map(int,input().split()))
