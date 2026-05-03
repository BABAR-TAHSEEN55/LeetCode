import java.awt.*;
import java.awt.event.*;

public class SimpleCalculator extends Frame implements ActionListener {

    TextField tf;
    Button add, sub, mul, div, eq, clr;
    Button numButtons[] = new Button[10];
    Panel p;

    double num1, num2, result;
    String operator;

    SimpleCalculator() {
        setLayout(new BorderLayout());

        tf = new TextField();
        add(tf, BorderLayout.NORTH);

        p = new Panel();
        p.setLayout(new GridLayout(5, 5));

        // Number buttons
        for (int i = 0; i <= 9; i++) {
            numButtons[i] = new Button(String.valueOf(i));
            numButtons[i].addActionListener(this);
        }

        // Operator buttons
        add = new Button("+");
        sub = new Button("-");
        mul = new Button("*");
        div = new Button("/");
        eq = new Button("=");
        clr = new Button("C");

        add.addActionListener(this);
        sub.addActionListener(this);
        mul.addActionListener(this);
        div.addActionListener(this);
        eq.addActionListener(this);
        clr.addActionListener(this);

        // Add buttons to panel
        p.add(numButtons[1]);
        p.add(numButtons[2]);
        p.add(numButtons[3]);
        p.add(add);

        p.add(numButtons[4]);
        p.add(numButtons[5]);
        p.add(numButtons[6]);
        p.add(sub);

        p.add(numButtons[7]);
        p.add(numButtons[8]);
        p.add(numButtons[9]);
        p.add(mul);

        p.add(numButtons[0]);
        p.add(eq);
        p.add(clr);
        p.add(div);

        add(p, BorderLayout.CENTER);

        setSize(800, 800);
        setTitle("Simple Calculator");
        setVisible(true);

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                dispose();
            }
        });
    }

    public void actionPerformed(ActionEvent e) {
        String cmd = e.getActionCommand();

        if (cmd.charAt(0) >= '0' && cmd.charAt(0) <= '9') {
            tf.setText(tf.getText() + cmd);
        } else if (cmd.equals("+") || cmd.equals("-") || cmd.equals("*") || cmd.equals("/")) {
            num1 = Double.parseDouble(tf.getText());
            operator = cmd;
            tf.setText("");
        } else if (cmd.equals("=")) {
            num2 = Double.parseDouble(tf.getText());

            switch (operator) {
                case "+":
                    result = num1 + num2;
                    break;
                case "-":
                    result = num1 - num2;
                    break;
                case "*":
                    result = num1 * num2;
                    break;
                case "/":
                    result = num1 / num2;
                    break;
            }

            tf.setText(String.valueOf(result));
        } else if (cmd.equals("C")) {
            tf.setText("");
        }
    }

    public static void main(String[] args) {
        new SimpleCalculator();
    }
}
