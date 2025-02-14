import java.awt.*;
import java.awt.event.*;

public class ListAction implements ActionListener{
ListAction(){
  Frame f = new Frame();
  Label label = new Label();
label.setAlignment(Label.CENTER);
label.setSize(400,300);
Button b = new Button("Show All");
b.setBounds(400,200,100,100);
final List l1 = new List(4,false);
l1.add("C++");
l1.add("Java");
l1.add("JavaScript");
l1.add("Rust");
f.add(l1);
f.add(b);
f.add(label);
f.setLayout(null);
f.setVisible(true);
f.setSize(400,200);
l1.addActionListener(this);
}
public void actionPerformed(ActionEvent e){
label.setText("Selected Language : " + e.getSelectedItem());// Get THis done
}
public static void main(String args[]){
  new ListAction();
}
}
