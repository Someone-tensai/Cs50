from cs50 import get_string

text = get_string("Text: ")
word_count = 1
sentence_count = 0
letter_count = 0
for l in text:
    if l == ' ':
        word_count += 1

    elif l == '.' or l == '!' or l == '?':
        sentence_count += 1

    elif l.isalpha():
        letter_count += 1

L = (letter_count/word_count) * 100
S = (sentence_count/word_count) * 100

index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")

elif index > 16:
    print("Grade 16+")

else:
    print(f"Grade {index}")
