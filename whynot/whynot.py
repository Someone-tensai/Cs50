a = 'SULAV PAUDEL'

l = list()
c = 0
def func():
    n = 0
    c = 0
    for char in a:
        l.append(char)
        if l[n] in a:
            print(l)
            n = n+1
    else:
        c += 1
        if c == 2:
            exit()
        else:
            func()

func()
