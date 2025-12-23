from cs50 import get_string

card = ' '
a = len(card)

while(a != 16 or a != 17 or a != 14 ):
    card = get_string("Number: ")
    a = len(card)
sum = 0
s1 = 0


for i in (a , 0 , -1):
    no = list.append(2 * int(i-1))
    nu = list.append(int(i))

for d in no:
    sum += (d)

for d in nu:
    s1 += (d)

total = sum + s1

if total % 10 == 0:
    if a == 15:
        print("AMEX")
    elif a == 13:
        print("Visa")
    elif a == 16:
        print("MASTERCARD")

else:
    print("INVALID")












