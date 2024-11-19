# Bonus Lab - Triangle
# Name: Madeline Frederick
# Date: 11/19/21
# Description: The user inputs the base and height of two triangles. The program computes the area
# of the triangles and outputs the larger one.

class Triangle:
    def __init__(self):
        self.base = 0
        self.height = 0

    def set_base(self, user_base):
        self.base = user_base

    def set_height(self, user_height):
        self.height = user_height

    def get_area(self):
        area = 0.5 * self.base * self.height
        return area

    def print_info(self):
        print('Base: {:.2f}'.format(self.base))
        print('Height: {:.2f}'.format(self.height))
        print('Area: {:.2f}'.format(self.get_area()))


if __name__ == "__main__":
    triangle1 = Triangle()
    triangle2 = Triangle()
    # Read and set base and height for triangle1 (use set_base() and set_height())
    triangle1.base = float(input())
    triangle1.height = float(input())
    # Read and set base and height for triangle2 (use set_base() and set_height())
    triangle2.base = float(input())
    triangle2.height = float(input())
    # Determine larger triangle (use get_area())
    triangle1area = float(triangle1.get_area())
    triangle2area = float(triangle2.get_area())
    print('Triangle with larger area:')
    # Output larger triangle's info (use print_info())
    if triangle1area > triangle2area:
        triangle1.print_info()
    elif triangle2area > triangle1area:
        triangle2.print_info()
