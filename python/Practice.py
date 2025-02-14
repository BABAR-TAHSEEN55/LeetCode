# # # # # # # class Employee: 
# # # # # # #     def __init__(self ,name , BasicAllowance , deduction , tip ):
# # # # # # #         self.name = name
# # # # # # #         self.BasicAllowance = BasicAllowance
# # # # # # #         self.deduction = deduction
# # # # # # #         self.tip= tip
# # # # # # #
# # # # # # #     def CalculateAllowance(self):
# # # # # # #          return self.BasicAllowance + self.tip
# # # # # # #
# # # # # # #     def Tax(self):
# # # # # # #          return (self.deduction + 1000)/2
# # # # # # #     def DisplayInfo(self):
# # # # # # #         print(f"Your Name : {self.name}")
# # # # # # #         print(f"Your Salary : {self.BasicAllowance}")
# # # # # # #         print(f"Your deduction : {self.deduction}")
# # # # # # #         print(f"Your Tip : {self.tip}")
# # # # # # #
# # # # # # # name = input("Enter your Name :")
# # # # # # # BasicAllowance = float(input("Enter your Salary  : "))
# # # # # # # deduction = float(input("Enter your deduction : "))
# # # # # # # tip = float(input("Enter your Tip : "))
# # # # # # #
# # # # # # # e1 = Employee(name, BasicAllowance , deduction , tip)
# # # # # # # e1.DisplayInfo()
# # # # # # #
# # # # # #
# # # # # # # Function to calculate grade
# # # # # # def calculate_grade(marks):
# # # # # #     if marks >= 90 and marks <= 100:
# # # # # #         return "A Grade"
# # # # # #     elif marks >= 80 and marks < 90:
# # # # # #         return "B Grade"
# # # # # #     elif marks >= 70 and marks < 80:
# # # # # #         return "C Grade"
# # # # # #     elif marks >= 60 and marks < 70:
# # # # # #         return "D Grade"
# # # # # #     elif marks >= 50 and marks < 60:
# # # # # #         return "E Grade"
# # # # # #     else:
# # # # # #         return "F Grade"
# # # # # #
# # # # # # # Taking input
# # # # # # marks = int(input("Enter your Marks: "))
# # # # # #
# # # # # # # Displaying the grade
# # # # # # grade = calculate_grade(marks)
# # # # # # print(f"Your grade is: {grade}")
# # # # # s1 = input("Enter your String : ")
# # # # # s2 = input("Enter your String : ")
# # # # # length = 0
# # # # # for i in s1:
# # # # #     length+=1
# # # # # print(length)
# # # # # if(len(s1)==len(s2)):
# # # # #     for i in range(len(s1)):
# # # # #         if(s1[i]!=s2[i]):
# # # # #             print("It is not Equal")
# # # # #             break
# # # # #         else:
# # # # #             print("It is Equal")
# # # # #             break
# # # # # else:
# # # # #     print("It is not Equal")
# # # # #
# # # # # if(s1.find('e')!=-1):
# # # # #     print("It is Present")
# # # # # else:
# # # # #     print("It is not Presetn")
# # # # #
# # # # #
# # # # x = ('Apple' , 'Mango' , 'choco')
# # # # y = ('Sup' , 'Wasup', 'Skibidi')
# # # # c = (x,y)
# # # # # print(x)
# # # # # print(y)
# # # # # print(c)
# # # # # # print(x+y)
# # # # for i in x:
# # # #     print(x)
# # # # print(x[0:1])
# # # # list = [1,2,3]
# # #
# # # # print(list)
# # #
# # # # import cmath
# # # #
# # # # a  = int(input("Enter Value of A : "))
# # # # b  = int(input("Enter Value of B : "))
# # # # c = int(input("Enter Value of C : "))
# # # #
# # # # des = (b**2)-4*a*c
# # # # r1 = (-b+cmath.sqrt(des))/2*a
# # # # r2 = (-b-cmath.sqrt(des))/2*a
# # # # print(f"Root 1 : {r1}")
# # # # print(f"Root 2 : {r2}")
# # #
# # # class Operation:
# # #     def __init__(self, a, b):
# # #         self.a = a
# # #         self.b = b
# # #
# # #     def addition(self):
# # #         return self.a + self.b
# # #
# # #     def subtraction(self):
# # #         return self.a - self.b
# # #
# # #
# # # # Get user input for initial values
# # # a = int(input("Enter Value of a: "))
# # # b = int(input("Enter Value of b: "))
# # #
# # # # Create an object of the class
# # # obj = Operation(a, b)
# # #
# # # # Menu-driven loop
# # # while True:
# # #     print("\nMenu:")
# # #     print("0. Exit")
# # #     print("1. Addition")
# # #     print("2. Subtraction")
# # #
# # #     choice = int(input("Enter your choice: "))
# # #
# # #     if choice == 1:
# # #         print("Result:", obj.addition())
# # #     elif choice == 2:
# # #         print("Result:", obj.subtraction())
# # #     elif choice == 0:
# # #         print("Exiting...")
# # #         break  # Exit the loop
# # #     else:
# # #         print("Invalid choice! Please try again.")
# # class Rectangle:
# #     def __init__(self, length , width):
# #          self.length = length
# #          self.width = width
# #     def CalCulateArea(self):
# #          return self.length *self.width
# # length = int(input("Enter Length : "))
# # width = int(input("Enter Width : "))
# # r1 = Rectangle(length,width)
# # r1.CalCulateArea();
# # print(f"Area of Rectange : {r1.CalCulateArea()}")
#
# class Animal:
#     def __init__(self, name):    # Fixed the double underscores
#         self.name = name
#
#     def speak(self):             # Changed to lowercase for convention
#         return "I am Speaking"
#
# class Dog(Animal):
#     def speak(self):             # This is method overriding
#         return "Woof Woffo"
#
# animal = Animal("Generic Animal")
# print(f"{animal.name} says  : {animal.speak()}")
# dog = Dog("Tom")
# # print(dog.speak())
#
# class shape:
#     def area(self):
#         return 0;
# class Rectange(shape):
#     def __init__(self,l,b):
#         self.l=l
#         self.b=b
#     def area(self):
#         return self.l*self.b
#
# rec = Rectange(2,5);
# sh = shape();
# print(f"Area : {rec.area()}")
# import re;
# pattern = r"^The.*Spain$"
# text="The Spain the teh 2Spain222"
# if(re.match(pattern,text)):
#     print("It does ")
# else:
#     print("It does not")
# a) List size n and n elements of list, then print the elements
n = int(input("Enter the number of elements in the list: "))
lst = []

for i in range(n):
    element = int(input(f"Enter element {i+1}: "))
    lst.append(element)

print("List elements:", lst)

# b) Delete an element from the list
del_element = int(input("Enter the element to delete: "))
if del_element in lst:
    lst.remove(del_element)
    print(f"List after deleting {del_element}: {lst}")
else:
    print(f"Element {del_element} not found in the list.")

# c) Sort the list
lst.sort()
print("Sorted list:", lst)

# d) Print elements less than the given key
key = int(input("Enter the key: "))
print(f"Elements less than {key}:")
for element in lst:
    if element < key:
        print(element, end=" ")
