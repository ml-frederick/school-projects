# Lab 1 - Calculate Quidditch Statistics
# Name: Madeline Frederick
# Date: 9/3/21

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

print("        Welcome to the CSE 1284 Quidditch Statistics Calculator")
print()
print("Enter the teams, scores, and time to make it work.  It's like magic!")
print()
print("What is the name of the team that caught the snitch?")
team_snitch = input()
print("What is the name of the other team?")
team_other = input()
print()
print("What is the final score of the team who caught the snitch?")
score_snitch = int(input())
print("What is the final score of the other team?")
score_other = int(input())
print()
print("How long did the game last in minutes?")
game_time = int(input())
print()
print(team_snitch + " Team Statistics")
print("Goals: ", (score_snitch - 150) / 10)
snitch1 = 1
print("Snitch: ", snitch1)
goalsmin_1 = ((score_snitch - 150) / 10) / game_time
print("Goals per Minute: {:.2f}".format(goalsmin_1))
print()
print(team_other + " Team Statistics")
print("Goals: ", (score_other / 10))
snitch2 = 0
print("Snitch: ", snitch2)
goalsmin_2 = (score_other / 10) / game_time
print("Goals per Minute: {:.2f}".format(goalsmin_2))


# See PyCharm help at https://www.jetbrains.com/help/pycharm/
