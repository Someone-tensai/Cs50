def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
  if len(s) >= 2 and len(s) <= 6:

    if not s[0:2].isalpha():
      return False
    for char in s:

        if not char.isalpha() and not char.isdigit():
            return False

        if char.isalpha():
             pass

        else:
            y= s[s.index(char): ]
            print(y)
            if y[0] == '0':
                return False

            for y in y:
                if y.isalpha():
                    return False
                if not y.isalpha() and not y.isdigit():
                    return False
        break
    return True




main()
