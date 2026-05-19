class AyaanThreadDemo {
        // Accessing the current thread
        Thread t = Thread.currentThread();
        
        // Displaying thread information
        System.out.println("Current Thread: " + t);
        
        // Getting thread name
        System.out.println("Thread Name: " + t.getName());
        
        // Changing thread name
        t.setName("MyMainThread");
        
        // Displaying updated thread name
        System.out.println("Updated Thread Name: " + t.getName());

}
class CurrentThreadDemo {
    public static void main(String[] args) {

    //Object
    AyaanThreadDemo ay = new AyaanThreadDemo()
        System.out.println(ay);

    }
}
