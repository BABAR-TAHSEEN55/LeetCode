class Box {
    private final int length;
    private final int width;
    private final int height;

    Box() {
        this(1, 1, 1);
    }

    Box(int length, int width, int height) {
        this.length = length;
        this.width = width;
        this.height = height;
    }

    Box(Box other) {
        this(other.length, other.width, other.height);
    }

    void display() {
        System.out.println("Length: " + length + ", Width: " + width + ", Height: " + height);
    }
}

public class Set1B_ConstructorDemo {
    public static void main(String[] args) {
        Box defaultBox = new Box();
        Box parameterizedBox = new Box(10, 20, 30);
        Box copiedBox = new Box(parameterizedBox);

        System.out.println("Default Constructor:");
        defaultBox.display();

        System.out.println("Parameterized Constructor:");
        parameterizedBox.display();

        System.out.println("Copy Constructor:");
        copiedBox.display();
    }
}
