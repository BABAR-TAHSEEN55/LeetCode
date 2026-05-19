interface Printable {
    void print();
}

abstract class Shape {
    abstract double area();

    void describe() {
        System.out.println("This is an abstract shape class.");
    }
}

class Circle extends Shape implements Printable {
    private final double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    @Override
    double area() {
        return Math.PI * radius * radius;
    }

    @Override
    public void print() {
        System.out.println("Circle radius: " + radius);
    }
}

public class Set3A_InterfaceAbstractDemo {
    public static void main(String[] args) {
        Circle circle = new Circle(7);
        circle.print();
        circle.describe();
        System.out.printf("Area of circle: %.2f%n", circle.area());
    }
}
