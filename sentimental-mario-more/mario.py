from cs50 import get_int

while True:
    n = get_int("Height: ")
    if(n <= 0 or n > 8):
        pass
    else:
        break

for i in range(1, n+1):
    for j in range(1, n+1):
        if j > n-i:
            print("#" , end="")
        else:
            print(" " , end="")
        if j == n:
            print(" ", "#" * i , end="")
    print()
