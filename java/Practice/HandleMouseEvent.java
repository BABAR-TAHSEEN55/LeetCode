
import java.awt.*;
import java.awt.event.*;

public class HandleMouseEvent implements MouseListener{
  Label l ;
  Frame f;
  HandleMouseEvent(){
    f = new Frame();
    l = new Label();
f.addMouseListener(this);
l.setAlignment(Label.CENTER);
l.setBounds(50,100,200,50);
l.setSize(400,300);
f.add(l);
f.setLayout(null);
f.setSize(400,300);
f.setVisible(true);
  }
  public void mouseClicked(MouseEvent e){
    l.setText("Mouse Clicked");
  }
  public void mouseEntered(MouseEvent e){
    l.setText("Mouse Entered");
  }

  public void mouseReleased(MouseEvent e){
    l.setText("Mouse Released");
  }

  public void mouseExited(MouseEvent e){
    l.setText("Mouse Exited");
  }

  public void mousePressed(MouseEvent e){
    l.setText("Mouse Presseds");
  }
   public static void main(String[] args) {
   new HandleMouseEvent(); 
  }
}

