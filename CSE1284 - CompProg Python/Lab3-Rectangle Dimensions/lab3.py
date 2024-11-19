# Lab 3 - Calculate Rectangle Dimensions
# Name: Madeline Frederick
# Date: 9/23/21

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

x_left = int(input("Enter the x coordinate for the lower left corner of the rectangle:\t"))
y_left = int(input("Enter the y coordinate for the lower left corner of the rectangle:\t"))
print()
width = int(input("Enter the width of the rectangle:\t"))
height = int(input("Enter the height of the rectangle:\t"))
print()
x_point = int(input("Enter the x coordinate of the point:\t"))
y_point = int(input("Enter the y coordinate of the point:\t"))
print()
x_wide = x_left + width
y_high = y_left + height
if x_left == x_point or x_point == x_wide:
    print("On the rectangle")
elif y_left == y_point or y_point == y_high:
    print("On the rectangle")
elif x_point in range(x_left, x_wide) and y_point in range(y_left, y_high):
    print("Inside the rectangle")
else:
    print("Outside the rectangle")
