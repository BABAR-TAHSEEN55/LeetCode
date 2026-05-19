import java.awt.Button;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.Label;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Set8B_AWTDemo extends Frame implements ActionListener {
    private final TextField nameField;
    private final Label messageLabel;

    Set8B_AWTDemo() {
        setTitle("AWT Demo");
        setSize(400, 200);
        setLayout(new FlowLayout());

        add(new Label("Enter your name:"));
        nameField = new TextField(20);
        add(nameField);

        Button button = new Button("Show Message");
        button.addActionListener(this);
        add(button);

        messageLabel = new Label(" ");
        add(messageLabel);

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
        messageLabel.setText("Hello, " + nameField.getText());
    }

    public static void main(String[] args) {
        new Set8B_AWTDemo();
    }
}
