known_plaintext = "the quick brown fox jumps over the lazy dog"
code_k_p = (len(known_plaintext),len(list(known_plaintext.split())))

cases = int(input())
input()

for case in range(cases):
    sentences = {}
    original = []

    aux = input()
    try:
        while aux != "":
            aux_len = len(aux)
            word_len = len(list(aux.split()))
            sentences.setdefault((aux_len, word_len),[]).append(aux)
            original.append(aux)
            aux = input()
    except Exception as e:
        #print(e)
        pass
    
    if sentences.setdefault(code_k_p,[]) == []:
        print("No solution.")
    else:
        flag = True
        for p in sentences.setdefault(code_k_p,[]):
            mapping = {}
            mapping[" "] = " "
            flag = True 
            for i,c in enumerate(list(p)):
                if mapping.get(c,known_plaintext[i]) != known_plaintext[i]:
                    flag = False
                    break
                mapping[c] = known_plaintext[i]
            if flag:
                break

        if flag:
            for o in original:
                print("".join(list(map(lambda c: mapping[c],list(o)))))    
        else:
            print("No solution.")
    
    if case != cases-1:
        print()