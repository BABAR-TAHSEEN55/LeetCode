class Person {
    void showPerson() {
        System.out.println("This is the base class Person.");
    }
}

class Employee extends Person {
    void showEmployee() {
        System.out.println("Employee inherits from Person.");
    }
}

class Manager extends Employee {
    void showManager() {
        System.out.println("Manager inherits from Employee.");
    }
}

public class Set6B_InheritanceDemo {
    public static void main(String[] args) {
        System.out.println("Single Level Inheritance:");
        Employee employee = new Employee();
        employee.showPerson();
        employee.showEmployee();

        System.out.println();
        System.out.println("Multi Level Inheritance:");
        Manager manager = new Manager();
        manager.showPerson();
        manager.showEmployee();
        manager.showManager();
    }
}
