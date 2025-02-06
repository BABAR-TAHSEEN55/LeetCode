
class Employee : 
    def __init__(self , name , basicAllowance , deduction , tip):
        self.name = name
        self.basicAllowance = (basicAllowance)
        self.deduction = (deduction)
        self.tip = (tip)


    def  calculateGrossSalary(self):
        return self.basicAllowance + self.tip
    def  Tax(self):
        return self.calculateGrossSalary() + (self.deduction/100)
    def displayInfo(self) :
        print(f"Employee: {self.name}")
        print(f"Gross Salary: ${self.calculateGrossSalary():}")
        print(f"Tax Deduction: ${self.Tax():.2f}")
        print(f"Net Salary: ${self.calculateGrossSalary() - self.Tax():.2f}")

name = input("Enter your name")
basicAllowance = float(input("Enter your salaray"))
deduction = float(input("Enter your deduction"))
tip = float(input("Enter your tip"))
e1 = Employee( name,basicAllowance,deduction,tip)
e1.displayInfo()
