import java.awt.*;
import java.awt.event.*;
public class AWTExample{
  public static void main(String args[]){
    Frame f = new Frame("AWT Example");
    f.setSize(400,300);
    f.setLayout(null);
    Label l = new Label("Enter your name");
    l.setBounds(40,40,100,30);
    f.add(l);
    TextField tf = new TextField();
    tf.setBounds(100,50,105, 20);
    f.add(tf);
    Checkbox c1 = new Checkbox("Accept Terms and Conditions");
    c1.setBounds(100,50,100,10);
    f.add(c1);
    f.setVisible(true);
  }
}

public class ButtonListener{
  public static void main(String args[]){
    Frame f = new Frame("Buton Example")
      TextField tf  = new TextField();
    tf.setBounds(100,54,10,20);
      f.add(tf);
      Button b = new  Button("CLICK ME !! For a Surprise")
        b.setBounds(100,40,30,10);
      b.addActionListener(new ActionListener(){
        public void ActionPerfomed(ActionEvent e ){
tf.setText("Welcome to RUST !!Point where everything is blazingly fast!!")
        }
      })
      f.add(b);
      f.setLayout(null);
      f.setSize(500,200);
      f.setVisible(true);
  }
}
// KeyListnere
public class KeyListener{
  public static void main(String args){
    Frame f = new Frame("Example of KeyLIstener");
    f.setSize(500,300);
    f.setLayout(null);
    f.setVisible(true);
    Label l = new Label("KEYS");
    l.setBounds(100,30,40,80);
    f.add(l);
f.addKeyListener(new KeyListener(){
  public void keyPressed(KeyEvent e){
    l.setText("Key Prewssed");
  }
  public void keyReleased(KeyEvent e){
    l.setText("Key released");
  }
  public void keyTyped(KeyEvent e){
    l.settext("KEY TYPED~");
  }
})
  }
}

}
public class MouseEvent{
  public static void main(String args[]){
    Frame f = new Frame("Mouse Event Example");
    Label l = new Label("Please Enter any key to listen");
    l.setBounds(50,10,20,10);
    l.setAlignment(Lable.CENTER);
    f.add(l);
    f.setLayout(null);
    f.setSize(100, 50);
    f.setVisible(true);
    f.addMouseListener(new MouseEvent(){
      public void mouseClicked(MouseEvent e){
        l.setText("mouse click3d")
      }
      public void mousePressed(MouseEvent e){
        l.setText("mouse Pressed");
      }
      public void mouseReleased(MouseEvent e){
        l.setText("mouse released");
      }

      public void mouseEntered(MouseEvent e){
        l.setText("mouse enterdd");
      }

      public void mouseExited(MouseEvent e){
        l.setText("mouse Exited");
      }
    })
  }
}
