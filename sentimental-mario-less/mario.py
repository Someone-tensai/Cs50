from cs50 import get_int
while True:
    n = get_int("Height: ")
    if n <= 0 or n > 8:
        pass
    else:
        break
k = 1
for i in range(n):
    for k in range(n-i-1):
        print(" ", end="")
    for j in range(i+1):
        print("#", end="")

    print()
