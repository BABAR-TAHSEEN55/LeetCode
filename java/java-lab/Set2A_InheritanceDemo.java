class Animal {
    void eat() {
        System.out.println("Animal eats food.");
    }
}



class Dog extends Animal {

    void bark() {
        System.out.println("Dog barks.");
    }

}

class Puppy extends Dog {
    void weep() {
        System.out.println("Puppy weeps.");
    }
}

public class Set2A_InheritanceDemo {
    public static void main(String[] args) {
        System.out.println("Single Level Inheritance:");
        Dog dog = new Dog();
        dog.eat();
        dog.bark();


        System.out.println();
        System.out.println("Multi Level Inheritance:");
        Puppy puppy = new Puppy();
        puppy.eat();
        puppy.bark();
        puppy.weep();
    }
}
