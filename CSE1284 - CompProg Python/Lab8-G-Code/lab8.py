# Lab 8 - G-Code
# Name: Madeline Frederick
# Date: 11/11/21

def processGcode(fileName, scale, offsetX, offsetY):
    with open(fileName) as f:
        lines = f.readlines()
    all_lists = []
    a = False
    for line in lines:
        if ";LAYER:0" in line:
            a = True
        elif ";LAYER:1" in line:
            a = False
        if a:
            x = False
            y = False
            if "G0" in line or "G1" in line:
                for value in line.split():
                    if "G0" in value:
                        extrude = False
                    if "G1" in value:
                        extrude = True
                    if "X" in value:
                        x = float(value[1:])
                    if "Y" in value:
                        y = float(value[1:])-
            if x and y:
                all_lists.append([x * scale + offsetX, y * scale + offsetY, extrude])
    return all_lists

def gCode(points):
    # Calling this function within zybooks will cause an error.
    import turtle
    wn = turtle.Screen()
    wn.tracer(0)  # Comment this line out to watch the turtle draw the contents of the file.
    t = turtle.Turtle()
    for x, y, extrude in points:
        if extrude:
            t.down()
        else:
            t.up()
        t.goto(x, y)
    wn.exitonclick()

if __name__ == "__main__":
    fileName = input()
    scale = int(input())
    offsetX, offsetY = int(input()), int(input())

    # The two file names are:
    # logo-m-state.gcode
    # football-logo_stand.gcode
    points = processGcode(fileName, scale, offsetX, offsetY)
    # To visualize the contents of the file, uncomment the next line
    # gCode(points)


--------------------------------------------------------------------------


def processGcode(fileName, scale, offsetX, offsetY):
    with open(fileName) as file:
        code = file.readlines()
    appendedlists = []
    read = False
    for line in code:
        if ";LAYER:0" in line:
            read = True
        elif ";LAYER:1" in line:
            read = False
        if read:
            x_coord = False
            y_coord = False
            if "G0" in line or "G1" in line:
                for word in line.split():
                    if "G0" in word:
                        extrude = False
                    if "G1" in word:
                        extrude = True
                    if "X" in word:
                        x_coord = float(word[1:])
                    if "Y" in word:
                        y_coord = float(word[1:])
            if x_coord and y_coord:
                appendedlists.append([x_coord * scale + offsetX, y_coord * scale + offsetY, extrude])
    return appendedlists


def gCode(points):
    # Calling this function within zybooks will cause an error.
    import turtle
    wn = turtle.Screen()
    wn.tracer(0)  # Comment this line out to watch the turtle draw the contents of the file.
    t = turtle.Turtle()
    for x, y, extrude in points:
        if extrude:
            t.down()
        else:
            t.up()
        t.goto(x, y)
    wn.exitonclick()


if __name__ == "__main__":
    fileName = input()
    scale = int(input())
    offsetX, offsetY = int(input()), int(input())

    # The two file names are:
    # logo-m-state.gcode
    # football-logo_stand.gcode
    points = processGcode(fileName, scale, offsetX, offsetY)
    # To visualize the contents of the file, uncomment the next line
    # gCode(points)
    print(points)



--------------------------------------------------------------------------------------------


def processGcode(fileName, scale, offsetX, offsetY):
    with open(fileName) as file:
        code = file.readlines()
    appendedlists = []
    read = False
    for line in code:
        if ";LAYER:0" in line:
            read = True
        elif ";LAYER:1" in line:
            read = False
        if read:
            x_coord = False
            y_coord = False
            if "X" in line and "Y" in line:
                for word in line.split():
                    if "X" in word:
                        x_coord = float(word[1:])
                    if "Y" in word:
                        y_coord = float(word[1:])
                    if "G1" in word:
                        extrude = True
                    if "G0" in word:
                        extrude = False
            if y_coord and x_coord:
                appendedlists.append([x_coord * scale + offsetX, y_coord * scale + offsetY, extrude])
    return appendedlists


def gCode(points):
    # Calling this function within zybooks will cause an error.
    import turtle
    wn = turtle.Screen()
    wn.tracer(0)  # Comment this line out to watch the turtle draw the contents of the file.
    t = turtle.Turtle()
    for x, y, extrude in points:
        if extrude:
            t.down()
        else:
            t.up()
        t.goto(x, y)
    wn.exitonclick()


if __name__ == "__main__":
    fileName = input()
    scale = int(input())
    offsetX, offsetY = int(input()), int(input())

    # The two file names are:
    # logo-m-state.gcode
    # football-logo_stand.gcode
    points = processGcode(fileName, scale, offsetX, offsetY)
    # To visualize the contents of the file, uncomment the next line
    # gCode(points)
    print(points)
    
