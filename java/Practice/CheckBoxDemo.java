import java.awt.*;
import java.awt.event.*;
public class CheckBoxDemo implements ItemListener{
    Checkbox c1 , c2;
    Label label ;
  CheckBoxDemo(){
    Frame f = new Frame();
    label = new Label();
    label.setAlignment(Label.CENTER);
    label.setSize(400,100);
    c1 = new Checkbox("C++");
    c2 = new Checkbox("java");
    c1.setBounds(100,100,50,50);
    c2.setBounds(100,150,50,50);
  f.add(label);
  f.add(c1);
f.add(c2);
f.setLayout(null);
f.setVisible(true);
f.setSize(400,300);
c1.addItemListener(this);
c2.addItemListener(this);
  }
  public void itemStateChanged(ItemEvent e){
    if(e.getSource()==c1){
      label.setText("C++ checkBox: "+ (e.getStateChange()==1?"Checked" : "UnChecked" ));
    }
    if(e.getSource()==c2){
      label.setText("Java checkBox: "+ (e.getStateChange()==1?"Checked" : "UnChecked" ));
    }
  }
  public static void main(String args[]){
    new CheckBoxDemo();
  }
}
