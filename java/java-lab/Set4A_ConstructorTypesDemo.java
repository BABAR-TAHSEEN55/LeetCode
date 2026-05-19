class Book {
    private final String title;
    private final double price;

    Book() {
        this("Unknown Book", 0.0);
    }

    Book(String title, double price) {
        this.title = title;
        this.price = price;
    }

    Book(Book other) {
        this(other.title, other.price);
    }

    void display() {
        System.out.println("Title: " + title + ", Price: " + price);
    }
}

public class Set4A_ConstructorTypesDemo {
    public static void main(String[] args) {
        Book first = new Book();
        Book second = new Book("Java Programming", 499.0);
        Book third = new Book(second);

        System.out.println("Default Constructor Output:");
        first.display();

        System.out.println("Parameterized Constructor Output:");
        second.display();

        System.out.println("Copy Constructor Output:");
        third.display();
    }
}
