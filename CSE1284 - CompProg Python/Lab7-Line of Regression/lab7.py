# Lab 7 - Line of Regression
# Name: Madeline Frederick
# Date: 10/29/21
# Description: This program generates random points based on a user-specified linear equation 
# prints the points, and computes a simple linear regression line.

import random
def generateRandomPointsWithTrend(line, count, tolerance):
    points = []
    random.seed(int(input("Seed: ")))
    for i in range(count):
        x = random.randint(0, 100)
        y = eval(line) + random.randint(-tolerance, tolerance)
        points.append(int(x))
        points.append(int(y))
    return points

def printPoints(xs, ys):
    string = "x\ty\n"
    for i in range(len(xs)):
        string += str(xs[i]) + "\t" + str(ys[i]) + "\n"
    return string

def separatePointsList(points):
    xs = points[0::2]
    ys = points[1::2]
    return xs, ys

def computeRegression(points):
    n = len(xs)
    x_bar = sum(xs) / n
    y_bar = sum(ys) / n
    a = 0
    b = 0
    for i in range(n):
        a += xs[i] * ys[i] - n * x_bar * y_bar
        b += xs[i]**2 - n *x_bar**2
    m = a/b
    return "y = "+ str(m) +' * x + '+ str(m * x_bar - y_bar)

if __name__ == "__main__":
    p = generateRandomPointsWithTrend(input("y = (enter the rest of the equation)"), int(input("Number of points")), int(input("Tolerance: ")))
    xs, ys = separatePointsList(p)
    print(printPoints(xs, ys))
    print("line of regression", computeRegression(p))
