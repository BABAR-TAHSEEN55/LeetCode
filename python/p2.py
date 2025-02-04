# class Marks : 
#     def __init__(self , marks ):
#         self.marks = marks
#     def CalculateGrade(self):
#         if self.marks>90:
#             print("A")
#         elif self.marks<=50:
#             print("B")
#     def DisplayInfo(self):
#             print(f"{self.marks }")
#
# cal = Marks(99)
# cal.CalculateGrade()
#
def CalculateGrade( marks):
    if marks >90:
        return "A"
    elif marks<89 and marks >70:
        return "B"

marks =float(input("Enter your mark"))
cal = CalculateGrade(marks)
print(cal)
