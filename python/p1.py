class Employee : 
    def __init__(self , name , basicAllowance , deduction , tip):
        self.name = name
        self.basicAllowance = float(basicAllowance)
        self.deduction = float(deduction)
        self.tip = float(tip)


    def  calculateGrossSalary(self):
        return self.basicAllowance + self.tip
    def  Tax(self):
        return self.calculateGrossSalary() + (self.deduction/100)
    def displayInfo(self) :
        print(f"Employee: {self.name}")
        print(f"Gross Salary: ${self.calculateGrossSalary():.2f}")
        print(f"Tax Deduction: ${self.Tax():.2f}")
        print(f"Net Salary: ${self.calculateGrossSalary() - self.Tax():.2f}")

name = input("Enter your name")
basicAllowance = input("Enter your salaray")
deduction = input("Enter your deduction")
tip = input("Enter your tip")
e1 = Employee( name,basicAllowance,deduction,tip)
e1.displayInfo()
