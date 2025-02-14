import java.util.*;
class IteratorDemo{
  ArrayList<String> al = new ArrayList<String>();
  al.add("A");
  al.add("B");
  al.add("C");
  al.add("D");
  System.out.println("Original Contents of the ArrayList : ");
  Iterator<String>itr = al.iterator();
  while (itr.hasNext()) {
    String element= itr.next();
    System.out.println(element +  " ");
    
  }
  System.out.println();
}
