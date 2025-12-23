from cs50 import get_float

while True:
    cash = get_float("Change: ")
    if (cash < 0):
        pass
    else:
        break

count = 0
change = cash * 100
while change > 0:

    if change >= 25:
        change = change - 25
        count += 1

    elif change >= 10:
        change = change - 10
        count += 1

    elif change >= 5:
        change = change - 5
        count += 1

    elif change >= 1:
        change = change - 1
        count += 1

print(count)
