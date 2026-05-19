class Calculator {
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
}

class Vehicle {
    void start() {
        System.out.println("Vehicle starts.");
    }
}

class Car extends Vehicle {
    @Override
    void start() {
        System.out.println("Car starts with a key.");
    }
}

public class Set2B_PolymorphismDemo {
    public static void main(String[] args) {
        Calculator calculator = new Calculator();
        System.out.println("Method Overloading:");
        System.out.println("add(10, 20) = " + calculator.add(10, 20));
        System.out.println("add(10, 20, 30) = " + calculator.add(10, 20, 30));

        System.out.println();
        System.out.println("Method Overriding:");
        Vehicle vehicle = new Car();
        vehicle.start();
    }
}
