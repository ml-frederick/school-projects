# Lab 2 - Calculate Rectangle Coordinates
# Name: Madeline Frederick
# Date: 9/17/21

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

print("This program will calculate all of the coordinates")
print("for the corners of a rectangle.")
print("But first you will need to enter a little data.")
print()
x_coordinate = input("Enter the x coordinate for the lower left corner of the rectangle:\t")
y_coordinate = input("Enter the y coordinate for the lower left corner of the rectangle:\t")
print()
rectangle_width = input("Enter the width of the rectangle:\t")
rectangle_height = input("Enter the height of the rectangle:\t")
print()
print("Here are your results.")
upperlefty = int(rectangle_height) + int(y_coordinate)
print("Upper Left Corner Coordinates:\t("+ str(x_coordinate) +", "+ str(upperlefty)+")")
upperrighty = int(rectangle_height) + int(y_coordinate)
upperrightx = int(x_coordinate) + int(rectangle_width)
print("Upper Right Corner Coordinates:\t("+ str(upperrightx)+", "+str(upperrighty)+")")
print("Lower Left Corner Coordinates:\t("+ str(x_coordinate) +", "+str(y_coordinate)+")")
lowerrightx = int(rectangle_width) + int(x_coordinate)
print("Lower Right Corner Coordinates:\t("+ str(lowerrightx)+", "+str(y_coordinate)+")")

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
