# Lab 6 - Dice Roll Simulator
# Name: Madeline Frederick
# Date: 10/22/21
# Description: The user and computer roll random numbers on 2 dice. The score is recorded to see who wins.

import random

def main():
    seed = int(input("Enter an integer to seed the random number generator:  \n"))
    random.seed(seed)
    totalplayer_score = 0
    totalcomputer_score = 0
    playAgain = True
    while playAgain:
        die1 = random.randint(1, 6)
        die2 = random.randint(1, 6)
        computer_die1 = random.randint(1, 6)
        computer_die2 = random.randint(1, 6)
        userScore = scoreRoll(die1,die2)
        computerScore = scoreRoll(computer_die1, computer_die2)
        print("You rolled: ", die1, die2)
        print("Your score: ", userScore)
        print()
        print("Computer rolled: ", computer_die1, computer_die2)
        print("Computer score: ", computerScore)
        print()
        die1, die2, userScore = reroll(die1,die2)
        print("The final scores:")
        print("You rolled: ", die1, die2)
        print("Your score: ", userScore)
        print()
        print("Computer rolled: ", computer_die1, computer_die2)
        print("Computer score: ", computerScore)
        print()
        totalplayer_score += userScore
        totalcomputer_score += computerScore
        print("Total user score:\t", totalplayer_score)
        print("Total computer score:\t", totalcomputer_score)
        print()
        print("Choose one of the following options:")
        print("1.  Continue Playing")
        print("2.  Stop Playing")
        selection = int(input("Selection:  "))
        while selection != 1 and selection != 2:
            print("Please select a 1 or a 2!")
            selection = int(input("Selection:  "))
        if selection == 2:
            playAgain = False
        else:
            print()
    print()
    if totalcomputer_score > totalplayer_score:
        print("The computer won.\nBetter luck next time.")
    elif totalplayer_score > totalcomputer_score:
        print("You beat the computer!\nGood job!")
    else:
        print("Good job")


def scoreRoll(x, y):
    if x + y == 3:
        score = 1000
    elif x == y:
        score = x * 100
    else:
        score = x * 10 + y
    return score

def reroll(x, y):
    print("Choose one of the following selections")
    print("1.  Reroll your first die")
    print("2.  Reroll your second die")
    print("3.  Keep your original roll")
    selection = int(input("Enter selection:  \n"))
    while not selection in [1, 2, 3]:
        print("Please enter 1, 2, or 3:")
        selection = int(input("Enter selection:   \n"))
    if selection == 1:
        x = random.randint(1, 6)
    elif selection == 2:
        y = random.randint(1, 6)
    score = scoreRoll(x,y)
    return x, y, score

if __name__ == "__main__":
    main()
