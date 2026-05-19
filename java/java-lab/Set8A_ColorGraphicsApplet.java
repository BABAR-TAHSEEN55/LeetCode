import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;

public class Set8A_ColorGraphicsApplet extends Applet {
    @Override
    public void paint(Graphics graphics) {
        setBackground(Color.WHITE);

        graphics.setColor(Color.BLUE);
        graphics.drawString("Color and Graphics Demo", 20, 30);

        graphics.setColor(Color.RED);
        graphics.fillRect(20, 50, 120, 60);

        graphics.setColor(Color.GREEN);
        graphics.fillOval(170, 50, 100, 60);

        graphics.setColor(Color.BLACK);
        graphics.drawLine(20, 140, 270, 140);
    }
}
