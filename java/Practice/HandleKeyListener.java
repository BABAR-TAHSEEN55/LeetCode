

import java.awt.*;
import java.awt.event.*;

public class  HandleKeyListener implements KeyListener{
  Label l ;
  Frame f;
  HandleKeyListener(){
    f = new Frame();
    l = new Label();
f.addKeyListener(this);
l.setAlignment(Label.CENTER);
l.setBounds(50,100,200,50);
l.setSize(400,300);
f.add(l);
f.setLayout(null);
f.setSize(400,300);
f.setVisible(true);
  }
  public void keyPressed(KeyEvent e){
    l.setText("Key PRessed");
  }
  public void keyReleased(KeyEvent e){
    l.setText("Key Relsed");
  }

  public void keyTyped(KeyEvent e){
    l.setText("Key Typed");
  }

   public static void main(String[] args) {
   new HandleKeyListener(); 
  }
}

