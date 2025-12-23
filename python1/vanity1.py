def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
  if len(s) >= 2 and len(s) <= 6:
   if s[0:2].isalpha():

        number_detected = False
        for char in s[2:]:
           if char.isdigit():
              if char != '0':
                 return True
                 number_detected=True
                 break



main()
