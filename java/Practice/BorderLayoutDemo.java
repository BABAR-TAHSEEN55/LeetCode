
import java.awt.*;
import java.awt.event.*;
public class BorderLayoutDemo{
  Label l ;
  Frame f;
  BorderLayoutDemo(){
    l = new Label();
    f = new Frame();
    Button b1 = new Button("Hello");
    Button b2 = new Button("to");
    Button b3 = new Button("New");
    Button b4 = new Button("Good");
    Button b5 = new Button("Studenst");
    f.add(b1,BorderLayout.NORTH);
    f.add(b2,BorderLayout.SOUTH);
    f.add(b3,BorderLayout.WEST);
    f.add(b4,BorderLayout.EAST);
    f.add(b5,BorderLayout.CENTER);
    f.setSize(400,300);
    f.setVisible(true);
  }
  public static void main(String args[]){
    new BorderLayoutDemo();
  }
}
