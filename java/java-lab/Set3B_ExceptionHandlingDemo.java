public class Set3B_ExceptionHandlingDemo {
    static void validateAge(int age) {
        if (age < 18) {
            throw new IllegalArgumentException("Age must be 18 or above.");
        }
        System.out.println("Eligible age: " + age);
    }

    public static void main(String[] args) {
        try {
            int number = 10;
            int result = number / 0;
            System.out.println("Result: " + result);
        } catch (ArithmeticException exception) {
            System.out.println("ArithmeticException caught: " + exception.getMessage());
        } finally {
            System.out.println("First exception block finished.");
        }

        try {
            validateAge(15);
        } catch (IllegalArgumentException exception) {
            System.out.println("Custom validation failed: " + exception.getMessage());
        }
    }
}
