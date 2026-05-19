import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class Set9_MouseKeyEventsApplet extends Applet implements MouseListener, KeyListener {
    private String message = "Click or press a key inside the applet.";
    private int mouseX;
    private int mouseY;

    @Override
    public void init() {
        addMouseListener(this);
        addKeyListener(this);
        setFocusable(true);
        setBackground(Color.LIGHT_GRAY);
    }

    @Override
    public void paint(Graphics graphics) {
        graphics.drawString(message, 20, 30);
        graphics.drawString("Mouse Position: (" + mouseX + ", " + mouseY + ")", 20, 55);
    }

    @Override
    public void mouseClicked(MouseEvent event) {
        mouseX = event.getX();
        mouseY = event.getY();
        message = "Mouse clicked.";
        repaint();
        requestFocus();
    }

    @Override
    public void keyPressed(KeyEvent event) {
        message = "Key pressed: " + event.getKeyChar();
        repaint();
    }

    @Override
    public void mousePressed(MouseEvent event) {
    }

    @Override
    public void mouseReleased(MouseEvent event) {
    }

    @Override
    public void mouseEntered(MouseEvent event) {
    }

    @Override
    public void mouseExited(MouseEvent event) {
    }

    @Override
    public void keyTyped(KeyEvent event) {
    }

    @Override
    public void keyReleased(KeyEvent event) {
    }
}
