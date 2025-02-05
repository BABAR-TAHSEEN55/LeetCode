# # import matplotlib.pyplot as plt
# # x = [1,3]
# # y = [2,8]
# # z=[6,1]
# # p=[8,10]
# # #plt.figure(figsize=(6,6))
# # plt.plot(x,y,z,p,marker="o",color="r")
# # plt.title("Haggu")
# # plt.xlabel("X-axis")
# # plt.ylabel("Y-axis")
# # plt.show()
#
#
#
# # Quadratic
# import cmath
# b = float(input("Enter Value of B"))
#
# a = float(input("Enter Value of a"))
# c = float(input("Enter Value of c"))
# d = (b**2)-4*a*c
# print("Determinant of this :",d)
#
# r1 = -b+(cmath.sqrt(d))/2*a
# r2 = -b-(cmath.sqrt(d))/2*a
# print(f"Solution of R1 : {r1} and same goes for r2")



class Rectangle:
    def __init__(self , length , breath):
        self.l = length
        self.b = breath
    def AreaOfRectangle(self):
        return self.l *self.b
    def DisplayArea(self):
        return self.AreaOfRectangle()
length = int(input("enter value of l"))
breadth = int(input("enter value of b"))
r1 = Rectangle(length, breadth)
print(f"Lenght : {length}")
print(f"breath : {breadth}")
print(f"Rectangle : {r1.DisplayArea()}")
