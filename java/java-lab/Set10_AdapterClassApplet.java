import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class Set10_AdapterClassApplet extends Applet {
    private String message = "Use mouse or keyboard inside the applet.";
    private int x = 20;
    private int y = 40;

    @Override
    public void init() {
        setBackground(Color.WHITE);
        setFocusable(true);

        addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent event) {
                x = event.getX();
                y = event.getY();
                message = "Mouse clicked using MouseAdapter.";
                repaint();
                requestFocus();
            }
        });

        addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent event) {
                message = "Key pressed using KeyAdapter: " + event.getKeyChar();
                repaint();
            }
        });
    }

    @Override
    public void paint(Graphics graphics) {
        graphics.drawString(message, x, y);
    }
}
