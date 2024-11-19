# Lab 5 - Exact Change
# Name: Madeline Frederick
# Date: 10/14/21
# Description: In this program, an amount of monetary change is input by the user.
# The program then outputs how much of each coin will be needed to make exact change.

num_dollars = 0
num_quarters = 0
num_dimes = 0
num_nickels = 0
num_pennies = 0

def exact_change(user_total):
    money = user_total
    num_dollars = int(user_total // 100)
    money = money % 100
    num_quarters = int(money // 25)
    money = money % 25
    num_dimes = int(money // 10)
    money = money % 10
    num_nickels = int(money // 5)
    money = money % 5
    num_pennies = int(money // 1)
    return (num_dollars, num_quarters, num_dimes, num_nickels, num_pennies)

if __name__ == '__main__':
    input_val = int(input())
    num_dollars, num_quarters, num_dimes, num_nickels, num_pennies = exact_change(input_val)

    user_total = input_val
    if user_total <= 0:
        print("no change")
    else:
        if num_dollars > 1:
            print(str(num_dollars) + " dollars")
        elif num_dollars == 1:
            print(str(num_dollars)+" dollar")
        if num_quarters > 1:
            print(str(num_quarters) + " quarters")
        elif num_quarters == 1:
            print(str(num_quarters)+" quarter")
        if num_dimes > 1:
            print(str(num_dimes) + " dimes")
        elif num_dimes == 1:
            print(str(num_dimes)+" dime")
        if num_nickels > 1:
            print(str(num_nickels) + " nickels")
        elif num_nickels == 1:
            print(str(num_nickels)+" nickel")
        if num_pennies > 1:
            print(str(num_pennies) + " pennies")
        if num_pennies == 1:
            print(str(num_pennies)+" penny")

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
