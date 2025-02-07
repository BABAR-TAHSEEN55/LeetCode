class Queue {
  private int item;
  private boolean available  = false;
  public synchronized int consume() {
    try {
      while (!available) { 
      wait();
      notify();
      System.out.println("It hass been consumer");
      }
    } catch (IOException e) {
System.out.println("Interrupted Exception");
    }
  }
}
