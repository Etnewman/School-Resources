// This "traditional" button click demo uses an ActionListener
// The next example uses Java 8's lambda function to implement
// the action listener
import javax.swing.JButton;
import javax.swing.JFrame;
import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ButtonNotLambda extends JFrame implements ActionListener
{
    public ButtonNotLambda( )
    {
        setSize(250, 100);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Action Listener");
        Container contentPane = getContentPane( );
        contentPane.setLayout(new FlowLayout( ));

        JButton goButton = new JButton("Click Me");
        goButton.addActionListener(this);
        contentPane.add(goButton);
    }

    public void actionPerformed(ActionEvent e)
    {
       System.out.println("You clicked me");
    }

    public static void main(String[] args)
    {
        ButtonNotLambda buttonGui = new ButtonNotLambda( );
        buttonGui.setVisible(true);
    }
}

