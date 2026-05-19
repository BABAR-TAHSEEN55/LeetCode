import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.Panel;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Set12_SimpleCalculator extends Frame implements ActionListener {
    private final TextField display;
    private double firstNumber;
    private String operator;

    Set12_SimpleCalculator() {
        setTitle("Simple Calculator");
        setSize(350, 400);
        setLayout(new BorderLayout());

        display = new TextField();
        add(display, BorderLayout.NORTH);

        Panel buttonPanel = new Panel(new GridLayout(4, 4, 5, 5));
        String[] buttonLabels = {
            "7", "8", "9", "+",
            "4", "5", "6", "-",
            "1", "2", "3", "*",
            "0", "%", "=", "C"
        };

        for (String label : buttonLabels) {
            Button button = new Button(label);
            button.addActionListener(this);
            buttonPanel.add(button);
        }

        add(buttonPanel, BorderLayout.CENTER);

        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent event) {
                dispose();
            }
        });

        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent event) {
        String command = event.getActionCommand();

        if (Character.isDigit(command.charAt(0))) {
            display.setText(display.getText() + command);
            return;
        }

        if ("+".equals(command) || "-".equals(command) || "*".equals(command) || "%".equals(command)) {
            firstNumber = Double.parseDouble(display.getText());
            operator = command;
            display.setText("");
            return;
        }

        if ("=".equals(command)) {
            double secondNumber = Double.parseDouble(display.getText());
            double result = 0;

            if ("+".equals(operator)) {
                result = firstNumber + secondNumber;
            } else if ("-".equals(operator)) {
                result = firstNumber - secondNumber;
            } else if ("*".equals(operator)) {
                result = firstNumber * secondNumber;
            } else if ("%".equals(operator)) {
                result = firstNumber % secondNumber;
            }

            display.setText(String.valueOf(result));
            return;
        }

        if ("C".equals(command)) {
            display.setText("");
            operator = null;
            firstNumber = 0;
        }
    }

    public static void main(String[] args) {
        new Set12_SimpleCalculator();
    }
}
