# Lab 4 - Password Transformer
# Name: Madeline Frederick
# Date: 9/30/21
# Description: This program transforms an input string by substituting 
# certain characters, making their password more complex.

word = input()
password = ''
i = 0
while i < len(word):
    if word[i] == "i":
        password += "1"
    elif word[i] == "a":
        password += "@"
    elif word[i] == "m":
        password += "M"
    elif word[i] == "B":
        password += "8"
    elif word[i] == "s":
        password += "$"
    else:
        password += word[i]
    i += 1
print(password + "!")
